import { Component, OnInit } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { Router } from '@angular/router';
import { FlashMessagesService } from 'angular2-flash-messages';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  username: string;
  password: string;

  constructor(
    private authService: AuthService,
    private router: Router,
    private flashMessageService: FlashMessagesService,
    ) {}

  ngOnInit() {
  }

  // this originates from ngModel binding.
  onLoginSubmit() {
    const user = {
      username: this.username,
      password: this.password
    }
    
    this.authService.authenticateUser(user).subscribe(data => {
      if ((<any>data).success) {
        this.authService.storeUserData((<any>data).token, (<any>data).user);
        this.flashMessageService.show('You are now logged in!', {cssClass: 'alert-success', timeout: 3000});
        this.router.navigate(['/profile']);
      }
      else {
        this.flashMessageService.show((<any>data).msg, {cssClass: 'alert-danger', timeout: 5000});
        this.router.navigate(['/login']);
      }
    });

  }

}
