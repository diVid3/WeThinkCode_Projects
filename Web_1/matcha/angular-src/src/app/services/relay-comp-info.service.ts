import { Injectable } from '@angular/core';
import { Observable, Subject } from 'rxjs';

// This service is intended to be used to relay infor-
// mation from a component to any other component(s).

@Injectable({
  providedIn: 'root'
})
export class RelayCompInfoService {

  private subject = new Subject<any>();

  // This is used so that components can retrieve an
  // observable to which they can subscribe to, in
  // turn to fire off observer in-line functions when
  // another component calls the subject.next method.
  getSubjectObs(): Observable<any> {
    return this.subject.asObservable();
  }

  // The component that calls this method will pass in
  // the desired boolean value, which will get passed
  // to the observer function in the component that's
  // subscribed to the observable above.
  showNavbarLogin(val: boolean): void {
    this.subject.next(val);
  }
  
  constructor() { }
}
