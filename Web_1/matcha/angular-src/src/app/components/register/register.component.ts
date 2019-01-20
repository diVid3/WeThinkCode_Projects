import { Component, OnInit } from '@angular/core';
import { ValidateService } from '../../services/validate.service';
import { AuthService } from '../../services/auth.service';
import { FlashMessagesService } from 'angular2-flash-messages';
import { Router } from '@angular/router';
import { LocateService } from '../../services/locate.service';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {

  firstName: string;
  lastName: string;
  username: string;
  age: string;
  gender: string = 'Male';
  sexuality: string = 'Bisexual';
  ipinfoLoc: string = 'Fetching ipinfoLoc...';
  email: string;
  password: string;

  constructor(
    private validateService: ValidateService, 
    private flashMessagesService: FlashMessagesService,
    private authService: AuthService,
    private router: Router,
    private locateService: LocateService
  ) { }

  ngOnInit() {
    this.locateService.locateUserIpinfo().subscribe(data => {
      this.ipinfoLoc = (<any>data).loc;
    });
  }

  onRegisterSubmit() {
    const user = {
      firstName: this.firstName,
      lastName: this.lastName,
      username: this.username,
      age: this.age,
      gender: this.gender,
      sexuality: this.sexuality,
      ipinfoLoc: this.ipinfoLoc,
      email: this.email,
      password: this.password
    }

    // Validate user fields.
    if (this.validateService.validateRegister(user) == false) {
       this.flashMessagesService.show('Please fill in all fields.', {cssClass: 'alert-danger', timeout: 6000});
       return false;
    }

    // Validate user email.
    if (this.validateService.validateEmail(user.email) == false) {
      this.flashMessagesService.show('Please use a valid email', {cssClass: 'alert-danger', timeout: 6000});
      return false;
    }

    // Not using <any> will result in the interpretation of type Object,
    // of which .success is not a native property.
    this.authService.registerUser(user).subscribe(data => {
      if ((<any>data).success) {
        this.flashMessagesService.show((<any>data).msg, {cssClass: 'alert-success', timeout: 3000});
        this.router.navigate(['/login']);
        return true;
      }
      else if (!((<any>data).success)) {
        this.flashMessagesService.show((<any>data).msg, {cssClass: 'alert-danger', timeout: 6000});
        return false;
      }
      this.flashMessagesService.show('Oops! Something went wrong, sorry about that :(', {cssClass: 'alert-danger', timeout: 6000});
      return false;
    });
  }
}
