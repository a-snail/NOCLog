#import "AppDelegate.h"

#define LOGLEVEL NSUIntegerMax
#import "NOCLog.h"


@interface AppDelegate ()
@end


@implementation AppDelegate

- (BOOL)application:(UIApplication *)application
didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    NOCLogD(@"%@%@\n%@%@",
            @"application  : ", application,
            @"launchOptions: ", launchOptions);

    NOCLogE(@"%@", @"Error Message!");
    NOCLogW(@"%@", @"Warning Message!");
    NOCLogI(@"%@", @"Information Message!");
    NOCLogV(@"%@", @"Verbose Message!");

    return YES;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    NOCLogD(@"application: %@", application);
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    NOCLogD(@"application: %@", application);
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
    NOCLogD(@"application: %@", application);
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    NOCLogD(@"application: %@", application);
}

- (void)applicationWillTerminate:(UIApplication *)application {
    NOCLogD(@"application: %@", application);
}

@end
