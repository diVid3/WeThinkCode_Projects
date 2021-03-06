import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { AuthService } from '../../services/auth.service';
import { FlashMessagesService } from 'angular2-flash-messages';
import { Router } from '@angular/router';

@Component({
  selector: 'app-view-profile',
  templateUrl: './view-profile.component.html',
  styleUrls: ['./view-profile.component.css']
})
export class ViewProfileComponent implements OnInit {

  public requestedProfileString: string;

  public user: Object;
  public long: number;
  public lat: number;

  public modalPictureSrc: any;

  constructor(
    private activatedRoute: ActivatedRoute,
    private authService: AuthService,
    private flashMessagesService: FlashMessagesService,
    private router: Router
  ) { }

  ngOnInit() {
    let loggedInUsername = JSON.parse(localStorage.getItem('user')).username;
    this.requestedProfileString = this.activatedRoute.snapshot.paramMap.get('username');

    if (this.requestedProfileString == loggedInUsername) {
      this.router.navigate(['/profile']);
      return;
    }

    this.authService.getRequestedProfile(this.requestedProfileString).subscribe((data) => {
      this.user = (<any>data).user;
      this.long = (<any>this.user).ipinfoLoc.coordinates[0];
      this.lat = (<any>this.user).ipinfoLoc.coordinates[1];
    })
  }

    // Probably a better way to do this, too tired though.

    setModalPictureSrc0() {
      this.modalPictureSrc = (<any>this.user).pictures[0];
    }
  
    setModalPictureSrc1() {
      this.modalPictureSrc = (<any>this.user).pictures[1];
    }
  
    setModalPictureSrc2() {
      this.modalPictureSrc = (<any>this.user).pictures[2];
    }
  
    setModalPictureSrc3() {
      this.modalPictureSrc = (<any>this.user).pictures[3];
    }

}
