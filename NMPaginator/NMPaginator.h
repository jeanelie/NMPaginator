//
//  NMPaginator.h
//
//  Created by Nicolas Mondollot on 07/04/12.
//

#import <Foundation/Foundation.h>

typedef enum {
    RequestStatusNone,
    RequestStatusInProgress,
    RequestStatusDone // request succeeded or failed
} RequestStatus;

@protocol NMPaginatorDelegate;

@interface NMPaginator : NSObject

@property (weak, nonatomic) id<NMPaginatorDelegate> delegate;

@property (assign, readonly) NSInteger pageSize; // number of results per page
@property (assign, readonly) NSInteger page; // number of pages already fetched
@property (assign, readonly) NSInteger total; // total number of results
@property (assign, readonly) RequestStatus requestStatus;
@property (nonatomic, strong, readonly) NSMutableArray *results;

- (id)initWithPageSize:(NSInteger)pageSize delegate:(id<NMPaginatorDelegate>)paginatorDelegate;

- (void)reset;
- (BOOL)reachedLastPage;

- (void)fetchFirstPage;
- (void)fetchNextPage;

// call these from subclass when you receive the results
- (void)receivedResults:(NSArray *)results total:(NSInteger)total;
- (void)failed;

@end

@protocol NMPaginatorDelegate <NSObject>

@required
- (void)paginator:(id)paginator didReceiveResults:(NSArray *)results;

@optional
- (void)paginatorDidFailToRespond:(id)paginator;
- (void)paginatorDidReset:(id)paginator;

@end
