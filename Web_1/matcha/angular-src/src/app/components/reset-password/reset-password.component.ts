import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { AuthService } from '../../services/auth.service';
import { FlashMessagesService } from 'angular2-flash-messages';
import { Router } from '@angular/router';

@Component({
  selector: 'app-reset-password',
  templateUrl: './reset-password.component.html',
  styleUrls: ['./reset-password.component.css']
})
export class ResetPasswordComponent implements OnInit {

  public token: string;
  public tokenValid: boolean;
  public displayForm: boolean;
  public newPassword: string;
  public newConfirmedPassword: string;
  // public user: any;

  constructor(
    private activatedRoute: ActivatedRoute,
    private authService: AuthService,
    private flashMessagesService: FlashMessagesService,
    private router: Router
  ) { }

  ngOnInit() {
    this.token = this.activatedRoute.snapshot.paramMap.get('token');
    console.log(this.token);

    // Need to check if the reset token is valid here.
    this.authService.checkResetTokenUser({resetToken: this.token})
    .subscribe((data) => {
      console.log((<any>data).msg);
      if ((<any>data).success == false) {
        this.flashMessagesService.show((<any>data).msg,
        {cssClass: 'alert-danger', timeout: 6000});
        // setTimeout(() => {                           // Weird hack?
        this.router.navigate(['/login']);
        // }, 7200);
      }
      else if ((<any>data).success == true)
        this.displayForm = true;
      else {
        this.flashMessagesService.show('Oops! Something went wrong.',
        {cssClass: 'alert-danger', timeout: 6000});
        this.router.navigate(['/login']);
      }
    });
  }

  onResetSubmit() {
    this.authService.updatePasswordUser(
      {
        newPassword: this.newPassword,
        newConfirmedPassword: this.newConfirmedPassword,
        // Use token to identify user for password update.
        resetToken: this.token
      }).subscribe(data => {
        if ((<any>data).success == false) {
          this.flashMessagesService.show((<any>data).msg,
          {cssClass: 'alert-danger', timeout: 6000});
        }
        else if ((<any>data).success == true) {
          this.flashMessagesService.show((<any>data).msg,
          {cssClass: 'alert-success', timeout: 3000});
        }
        else {
          this.flashMessagesService.show('Oops! Something went wrong.',
          {cssClass: 'alert-danger', timeout: 6000});
        }
      });
  }
}
