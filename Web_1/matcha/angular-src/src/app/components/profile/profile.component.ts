import { Component, OnInit } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.css']
})
export class ProfileComponent implements OnInit {

  user: Object;
  long: number;
  lat: number;

  constructor(
    private authService: AuthService,
    private router: Router
  ) {
    
  }

  // We're going to display the user profile when the component initializes.
  ngOnInit() {
    this.authService.getProfile().subscribe(profile => {
      this.user = (<any>profile).user;
      console.log(this.user);
      this.long = (<any>this.user).ipinfoLoc.coordinates[0];
      this.lat = (<any>this.user).ipinfoLoc.coordinates[1];
    },
    err => {
      console.log(err);
      return false;
    });
  }

}
