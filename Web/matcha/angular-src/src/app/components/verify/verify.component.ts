import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { AuthService } from '../../services/auth.service';
import { FlashMessagesService } from 'angular2-flash-messages';
import { Router } from '@angular/router';

@Component({
  selector: 'app-verify',
  templateUrl: './verify.component.html',
  styleUrls: ['./verify.component.css']
})
export class VerifyComponent implements OnInit {

  public token: string;

  constructor(
    private activatedRoute: ActivatedRoute,
    private authService: AuthService,
    private flashMessagesService: FlashMessagesService,
    private router: Router
  ) { }

  ngOnInit() {
    this.token = this.activatedRoute.snapshot.paramMap.get('token');

    this.authService.checkVerifyToken({verifyToken: this.token}).subscribe(data => {
      if ((<any>data).success == false) {
        this.flashMessagesService.show((<any>data).msg,
        {cssClass: 'alert-danger', timeout: 6000});
        this.router.navigate(['/login']);
      }
      else if ((<any>data).success == true) {
        this.flashMessagesService.show((<any>data).msg,
        {cssClass: 'alert-success', timeout: 4000});
        this.router.navigate(['/login']);
      }
      else {
        this.flashMessagesService.show('Oops! Something went wrong.',
        {cssClass: 'alert-danger', timeout: 6000});
        this.router.navigate(['/login']);
      }
    });
  }

}
