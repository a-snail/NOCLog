#import "ViewController.h"

#define LOGLEVEL NSUIntegerMax
#import "NOCLog.h"


@interface ViewController ()
@end


@implementation ViewController

- (void)viewDidLoad {
    NOCLogD(@"");
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    NOCLogD(@"");
    [super didReceiveMemoryWarning];
}

@end
