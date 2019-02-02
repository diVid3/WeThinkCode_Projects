import { Component, OnInit, ViewChild, AfterViewInit } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { Router } from '@angular/router';
import { FlashMessagesService } from 'angular2-flash-messages';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.css']
})
export class SearchComponent implements OnInit, AfterViewInit {

  @ViewChild('intersectionTrigger') intersectionTrigger;

  // These are good defaults:
  // public locationHigh: number = 999999;
  // public locationLow: number = 0.001;
  // public fameHigh: number = 999999;
  // public fameLow: number = 0;
  // public ageHigh: number = 100;
  // public ageLow: number = 18;

  public userData: any;
  public userLong: string;
  public userLat: string;

  public searchClicked: boolean = false;
  public docArr: any;
  public noResults: boolean;

  public searchObj: any;
  public limit: number = 5;
  public skip: number = 0;                // Total number to skip.
  public skipIncrement: number = 5;       // Number to increment total skip by.
  public sort: Object = {};               // e.g. { "_id" : 1 }.

  public sortExpandClicked: boolean = false;
  public filterExpandClicked: boolean = false;

  // Remember location is in km, mongo uses m.
  public locationHigh: number;
  public locationLow: number;
  public fameHigh: number;
  public fameLow: number;
  public ageHigh: number;
  public ageLow: number;

  public matchaChecked: boolean = false;
  public sportsChecked: boolean = false;
  public artChecked: boolean = false;
  public gamingChecked: boolean = false;
  public travelingChecked: boolean = false;
  public musicChecked: boolean = false;
  public cookingChecked: boolean = false;
  public readingChecked: boolean = false;
  public computersChecked: boolean = false;
  public moviesChecked: boolean = false;

  constructor(
    private authService: AuthService,
    private router: Router,
    private flashMessageService: FlashMessagesService,
  ) { }

  ngOnInit() {
    this.userData = JSON.parse(localStorage.getItem('user'));
    this.userLong = this.userData.ipinfoLoc.coordinates[0];
    this.userLat = this.userData.ipinfoLoc.coordinates[1];
  }

  ngAfterViewInit() {
  }

  onSearchSubmit() {
    let interestArr = [];

    if (this.matchaChecked) interestArr.push('Matcha');
    if (this.sportsChecked) interestArr.push('Sports');
    if (this.artChecked) interestArr.push('Art');
    if (this.gamingChecked) interestArr.push('Gaming');
    if (this.travelingChecked) interestArr.push('Traveling');
    if (this.musicChecked) interestArr.push('Music');
    if (this.cookingChecked) interestArr.push('Cooking');
    if (this.moviesChecked) interestArr.push('Movies');
    if (this.computersChecked) interestArr.push('Computers');
    if (this.readingChecked) interestArr.push('Reading');

    let searchObj = {
      userLong: this.userLong,
      userLat: this.userLat,
      locationHigh: this.locationHigh,
      locationLow: this.locationLow,
      fameHigh: this.fameHigh,
      fameLow: this.fameLow,
      ageHigh: this.ageHigh,
      ageLow: this.ageLow,
      interestArr,
      limit: this.limit,
      skip: this.skip,
      sort: this.sort
    }

    if (searchObj.locationHigh)
      searchObj.locationHigh = searchObj.locationHigh * 1000;
    if (searchObj.locationLow)
      searchObj.locationLow = searchObj.locationLow * 1000;

    this.authService.searchUsers(searchObj).subscribe((data) => {
      if ((<any>data).success == true) {
        this.docArr = (<any>data).docs;
        if (this.docArr.length == 0)
          this.noResults = true;
        this.searchClicked = true;

        if (this.noResults == true)
          return;

        // This ensure that the call stack is cleared before executing, thus
        // acting as a life-cycle hook? Right after *ngIf inserted DOM elements.
        setTimeout(() => {
          const observer = new IntersectionObserver((entries) => {
            entries.forEach((entry) => {

              if (entry.intersectionRatio > 0) {
                let searchObj = {
                  userLong: this.userLong,
                  userLat: this.userLat,
                  locationHigh: this.locationHigh,
                  locationLow: this.locationLow,
                  fameHigh: this.fameHigh,
                  fameLow: this.fameLow,
                  ageHigh: this.ageHigh,
                  ageLow: this.ageLow,
                  interestArr,
                  limit: this.limit,
                  skip: (this.skip += this.skipIncrement),
                  sort: this.sort,
                }

                if (searchObj.locationHigh)
                  searchObj.locationHigh = searchObj.locationHigh * 1000;
                if (searchObj.locationLow)
                  searchObj.locationLow = searchObj.locationLow * 1000;

                console.log('Send load request');

                // Might need to throttle request here.
                this.authService.searchUsers(searchObj).subscribe((data) => {
                  let tempDocArr = (<any>data).docs;
                  tempDocArr.forEach((doc) => {
                    this.docArr.push(doc);
                  });
                });
              }

            });

          }, {});
          observer.observe(<Element>(this.intersectionTrigger.nativeElement));
        }, 5);

      }
      else
        this.flashMessageService.show((<any>data).msg, {cssClass:
          'alert-danger', timeout: 5000});
    });
  }

  // Button for testing purposes.
  autofill() {
    this.locationHigh = 100000;
    this.locationLow = 0.001;
    this.fameHigh = 999999;
    this.fameLow = 0;
    this.ageHigh = 100;
    this.ageLow = 18;

    this.matchaChecked = true;
    this.sportsChecked = true;
    this.artChecked = true;
    this.gamingChecked = true;
    this.travelingChecked = true;
    this.musicChecked = true;
    this.cookingChecked = true;
    this.readingChecked = true;
    this.computersChecked = true;
    this.moviesChecked = true;
  }

  resetForm() {
    this.searchClicked = false;
    this.noResults = false;
    this.skip = 0;

    this.locationHigh = undefined;
    this.locationLow = undefined;
    this.fameHigh = undefined;
    this.fameLow = undefined;
    this.ageHigh = undefined;
    this.ageLow = undefined;

    this.matchaChecked = false;
    this.sportsChecked = false;
    this.artChecked = false;
    this.gamingChecked = false;
    this.travelingChecked = false;
    this.musicChecked = false;
    this.cookingChecked = false;
    this.readingChecked = false;
    this.computersChecked = false;
    this.moviesChecked = false;
  }

  searchAgain() {
    this.resetForm();
    this.searchClicked = false;
  }

  // profileRedirect(username) {
  //   let loggedInUser = JSON.parse(localStorage.getItem('user'));
  //   if (username == loggedInUser.username)
  //     this.router.navigate(['/profile']);
  //   else
  //     this.router.navigate(['/view-profile/', username]);
  // }

  sortExpand() {
    this.filterExpandClicked = false;

    if (!this.sortExpandClicked)
      this.sortExpandClicked = true;
    else
      this.sortExpandClicked = false;
  }
  
  filterExpand() {
    this.sortExpandClicked = false;
    
    if (!this.filterExpandClicked)
      this.filterExpandClicked = true;
    else
      this.filterExpandClicked = false;
  }

  onSortSubmit() {
    console.log("onSortSubmit clicked!");
  }

  onFilterSubmit() {
    console.log("onFilterSubmit clicked!");
  }

}
