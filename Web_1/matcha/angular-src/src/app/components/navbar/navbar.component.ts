// import { Component, OnInit } from '@angular/core';
import { Component, OnInit, OnDestroy } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { Router } from '@angular/router';
import { FlashMessagesService } from 'angular2-flash-messages';
import { Subscription } from 'rxjs';
// import { RelayCompInfoService } from '../../services/relay-comp-info.service';

@Component({
  selector: 'app-navbar',
  templateUrl: './navbar.component.html',
  styleUrls: ['./navbar.component.css']
})
export class NavbarComponent implements OnInit, OnDestroy {

  // Properties for toggling menu in mobile view.
  mobMenu: string = "navbar-collapse collapse";
  isShowClassActive: number = 0;

  // Used to display or hide login button depending
  // on login/logout state.
  // displayLogin: boolean = true;
  subscription: Subscription;

  // constructor() { }
  constructor(
    private authService: AuthService,
    private router: Router,
    private flashMessageService: FlashMessagesService,
    // private relayCompInfoService: RelayCompInfoService) {
      // Observer in-line method here. The val (value) variable
      // here will be get passed in from the subject.next method
      // from the relay-comp-info.service, the service in turn gets
      // the val variable from the other component that calls the
      // method hideNavbarLogin() and passes in a value to it.
    //   this.subscription = this.relayCompInfoService.getSubjectObs()
    //     .subscribe(val => {this.displayLogin = val;});
    // }
    ) {}
  
  ngOnInit() {
    // if (localStorage.getItem('user') !== null) {
    //   this.displayLogin = false;
    // }
  }

  // Unsubscribe to ensure no memory leaks.
  ngOnDestroy() {
    this.subscription.unsubscribe();
  }

  // Method to toggle drop down menu in mobile view.
  toggleMobileDropdown() {
    if (this.isShowClassActive == 0) {
      this.mobMenu = "navbar-collapse collapse show";
      this.isShowClassActive = 1;
    }
    else {
      this.mobMenu = "navbar-collapse collapse";
      this.isShowClassActive = 0;
    }
  }

  onLogoutClick() {
    this.authService.logout();
    // this.displayLogin = true;
    this.flashMessageService.show('You are logged out.', {cssClass: 'alert-success', timeout: 3000});
    this.router.navigate(['/']);
    return false;
  }

}
