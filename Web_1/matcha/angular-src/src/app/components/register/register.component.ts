import { Component, OnInit } from '@angular/core';
import { ValidateService } from '../../services/validate.service';
import { AuthService } from '../../services/auth.service';
import { FlashMessagesService } from 'angular2-flash-messages';
import { Router } from '@angular/router';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {

  firstName: string;
  lastName: string;
  // name: string;
  username: string;
  gender: string = 'Male';
  email: string;
  password: string;

  constructor(
    private validateService: ValidateService, 
    private flashMessagesService: FlashMessagesService,
    private authService: AuthService,
    private router: Router) { }

  ngOnInit() {
  }

  onRegisterSubmit() {
    const user = {
      // name: this.name,
      firstName: this.firstName,
      lastName: this.lastName,
      username: this.username,
      gender: this.gender,
      email: this.email,
      password: this.password
    }

    // Validate user fields.
    if (this.validateService.validateRegister(user) == false) {
       this.flashMessagesService.show('Please fill in all fields.', {cssClass: 'alert-danger', timeout: 3000});
       return false;
    }

    // Validate user email.
    if (this.validateService.validateEmail(user.email) == false) {
      this.flashMessagesService.show('Please use a valid email', {cssClass: 'alert-danger', timeout: 3000});
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
        this.flashMessagesService.show((<any>data).msg, {cssClass: 'alert-danger', timeout: 3000});
        this.router.navigate(['/register']);
        return false;
      }
      this.flashMessagesService.show('Oops! Something went wrong, sorry about that :(', {cssClass: 'alert-danger', timeout: 3000});
      return false;
    });
  }
}
