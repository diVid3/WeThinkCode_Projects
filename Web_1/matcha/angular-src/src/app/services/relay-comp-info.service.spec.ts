import { TestBed } from '@angular/core/testing';

import { RelayCompInfoService } from './relay-comp-info.service';

describe('RelayCompInfoService', () => {
  beforeEach(() => TestBed.configureTestingModule({}));

  it('should be created', () => {
    const service: RelayCompInfoService = TestBed.get(RelayCompInfoService);
    expect(service).toBeTruthy();
  });
});
