import { Component, OnInit, ViewChild, AfterViewInit, OnDestroy, HostListener } from '@angular/core';
import { AuthService } from '../../services/auth.service';
import { Router } from '@angular/router';
import { FlashMessagesService } from 'angular2-flash-messages';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.css']
})
export class SearchComponent implements OnInit, AfterViewInit, OnDestroy {

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
  
  public loading: boolean = false;

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

  public interestArr: string[] = [];

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

  public searchWindowScrollY: number = 0;

  constructor(
    private authService: AuthService,
    private router: Router,
    private flashMessageService: FlashMessagesService,
  ) { }

  ngOnInit() {
    this.userData = JSON.parse(localStorage.getItem('user'));
    this.userLong = this.userData.ipinfoLoc.coordinates[0];
    this.userLat = this.userData.ipinfoLoc.coordinates[1];

    // Can set variables here if localStorage contains a previous search.
    // Remember to unserialze them with JSON.parse.
    let docArrString = localStorage.getItem('searchDocArr');
    let searchQueryString = localStorage.getItem('searchQuery');

    if (docArrString && searchQueryString) {
      this.docArr = JSON.parse(docArrString);
      this.searchClicked = true;

      // Need to set local variables to searchQuery.
      let searchQuery = JSON.parse(searchQueryString);

      // Setting local variables to stored variables as to enable infinite
      // scroll.
      this.userLong = searchQuery.userLong;
      this.userLat = searchQuery.userLat;
      this.locationHigh = searchQuery.locationHigh;
      this.locationLow = searchQuery.locationLow;
      this.fameHigh = searchQuery.fameHigh;
      this.fameLow = searchQuery.fameLow;
      this.ageHigh = searchQuery.ageHigh;
      this.ageLow = searchQuery.ageLow;
      this.interestArr = searchQuery.interestArr;
      this.limit = searchQuery.limit;
      this.skip = searchQuery.skip;
      this.sort = searchQuery.sort;
    }
  }

  ngOnDestroy() {
    let windowScrollYString = JSON.stringify(this.searchWindowScrollY)
    localStorage.setItem('searchWindowScrollY', windowScrollYString);
  }

  ngAfterViewInit() {
    // Adding intersection observer if a search query was saved.
    let docArrString = localStorage.getItem('searchDocArr');
    let searchQueryString = localStorage.getItem('searchQuery');

    if (docArrString && searchQueryString) {
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
              interestArr: this.interestArr,
              limit: this.limit,
              skip: (this.skip += this.skipIncrement),
              sort: this.sort,
            }

            this.loading = true;

            // Throttling request here.
            setTimeout(() => {
              this.authService.searchUsers(searchObj).subscribe((data) => {
                if ((<any>data).success == true) {
                  this.loading = false;
                  let tempDocArr = (<any>data).docs;
                  tempDocArr.forEach((doc) => {
                    this.docArr.push(doc);
                  });

                  // Storing search query in local storage.
                  let searchObjString = JSON.stringify(searchObj);
                  localStorage.setItem('searchQuery', searchObjString);

                  // Storing search results in local storage.
                  let docArrString = JSON.stringify(this.docArr);
                  localStorage.setItem('searchDocArr', docArrString);
                }
                else {
                  this.loading = false;
                }
              });
            }, 500);

          }

        });

      }, {});

      observer.observe(<Element>(this.intersectionTrigger.nativeElement));
    }

    // Resetting the previous vertical scroll position.
    if (localStorage.getItem('searchWindowScrollY')) {
      let windowScrollYString = localStorage.getItem('searchWindowScrollY');
      let windowVerticalScrollTarget = JSON.parse(windowScrollYString);
      window.scrollTo(0, windowVerticalScrollTarget);
    }
  }

  onSearchSubmit() {

    // Clearing interestArr if it contains elements of last search.
    if (this.interestArr.length > 0) this.interestArr.length = 0;

    if (this.matchaChecked) this.interestArr.push('Matcha');
    if (this.sportsChecked) this.interestArr.push('Sports');
    if (this.artChecked) this.interestArr.push('Art');
    if (this.gamingChecked) this.interestArr.push('Gaming');
    if (this.travelingChecked) this.interestArr.push('Traveling');
    if (this.musicChecked) this.interestArr.push('Music');
    if (this.cookingChecked) this.interestArr.push('Cooking');
    if (this.moviesChecked) this.interestArr.push('Movies');
    if (this.computersChecked) this.interestArr.push('Computers');
    if (this.readingChecked) this.interestArr.push('Reading');

    let searchObj = {
      userLong: this.userLong,
      userLat: this.userLat,
      locationHigh: this.locationHigh,
      locationLow: this.locationLow,
      fameHigh: this.fameHigh,
      fameLow: this.fameLow,
      ageHigh: this.ageHigh,
      ageLow: this.ageLow,
      interestArr: this.interestArr,
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

        // Storing search query in local storage.
        let searchObjString = JSON.stringify(searchObj);
        localStorage.setItem('searchQuery', searchObjString);

        // Storing search results in local storage.
        let docArrString = JSON.stringify(this.docArr);
        localStorage.setItem('searchDocArr', docArrString);

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
                  interestArr: this.interestArr,
                  limit: this.limit,
                  skip: (this.skip += this.skipIncrement),
                  sort: this.sort,
                }

                if (searchObj.locationHigh)
                  searchObj.locationHigh = searchObj.locationHigh * 1000;
                if (searchObj.locationLow)
                  searchObj.locationLow = searchObj.locationLow * 1000;

                this.loading = true;

                // Throttling request here.
                setTimeout(() => {
                  this.authService.searchUsers(searchObj).subscribe((data) => {
                    if ((<any>data).success == true) {
                      this.loading = false;
                      let tempDocArr = (<any>data).docs;
                      tempDocArr.forEach((doc) => {
                        this.docArr.push(doc);
                      });

                      // Storing search query in local storage.
                      let searchObjString = JSON.stringify(searchObj);
                      localStorage.setItem('searchQuery', searchObjString);

                      // Storing search results in local storage.
                      let docArrString = JSON.stringify(this.docArr);
                      localStorage.setItem('searchDocArr', docArrString);
                    }
                    else {
                      this.loading = false;
                    }
                  });
                }, 500);

              }

            });

          }, {});

          observer.observe(<Element>(this.intersectionTrigger.nativeElement));
        }, 50);

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

    if (localStorage.getItem('searchQuery'))
      localStorage.removeItem('searchQuery');

    if (localStorage.getItem('searchDocArr'))
      localStorage.removeItem('searchDocArr');

    if (localStorage.getItem('searchWindowScrollY'))
      localStorage.removeItem('searchWindowScrollY');

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

  @HostListener('window:scroll', ['$event'])
  saveSearchScrollY(event) {
    this.searchWindowScrollY = window.scrollY;
  }

}
