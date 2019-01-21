import { Component, OnInit } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { FlashMessagesService } from 'angular2-flash-messages';

@Component({
  selector: 'app-forgot-password',
  templateUrl: './forgot-password.component.html',
  styleUrls: ['./forgot-password.component.css']
})
export class ForgotPasswordComponent implements OnInit {

  enteredEmail: string;

  constructor(
    private authService: AuthService,
    private flashMessagesService: FlashMessagesService
  ) { }

  onPasswordResetSubmit() {
    if (this.enteredEmail == null || this.enteredEmail == '') {
      this.flashMessagesService.show('Please enter an email address',
      {cssClass: 'alert-danger', timeout: 6000});
      return;
    }
    // this.enteredEmailObj.
    this.authService.resetPasswordUser({ enteredEmail : this.enteredEmail }).subscribe((data) => {
      // success: false, msg: something
      console.log(data);
    });
  }

  ngOnInit() {
  }

}
