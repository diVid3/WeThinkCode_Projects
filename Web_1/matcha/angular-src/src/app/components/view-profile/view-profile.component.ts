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

  constructor(
    private activatedRoute: ActivatedRoute,
    private authService: AuthService,
    private flashMessagesService: FlashMessagesService,
    private router: Router
  ) { }

  ngOnInit() {
    this.requestedProfileString = this.activatedRoute.snapshot.paramMap.get('username');
    this.authService.getRequestedProfile(this.requestedProfileString).subscribe((data) => {
      this.user = (<any>data).user;
      this.long = (<any>this.user).ipinfoLoc.coordinates[0];
      this.lat = (<any>this.user).ipinfoLoc.coordinates[1];
    })
  }

}
