#import "NOCLog.h"


extern void NOCExceptionHandler(NSException *exception) {
    NSString *frm = nil;
    NSString *msg = @"[NOCLog] - Uncaught Exception ";
    NSUInteger to = (NSUInteger)80;
    NSUInteger ln = to - msg.length;
    NSString *del = [@"" stringByPaddingToLength:ln
                                      withString:@"-"
                                 startingAtIndex:(NSUInteger)0];

    msg = [msg stringByAppendingString:del];
    del = [@"" stringByPaddingToLength:to
                            withString:@"-"
                       startingAtIndex:(NSUInteger)0];

    NSArray *address = [exception callStackReturnAddresses];
    NSArray *symbols = [exception callStackSymbols];

    frm = @"\n\n%@\n%@%@\n%@%@\n%@\n%@%@\n%@\n%@\n%@\n%@\n%@\n%@\n";
    msg = [NSString stringWithFormat:frm, msg,
           @"Name   : ", exception.name,
           @"Reason : ", exception.reason,
           del,
           @"Exception : ", exception,
           del,
           @"StackAddress : ", address,
           @"StackSymbols : ", symbols,
           del];
    NSLog(@"%s", [msg UTF8String]);
}


@interface NOCLog ()

#pragma mark - Private properties

@property (readwrite, assign, nonatomic) NSUInteger lenDelimiter;

@end


@implementation NOCLog

#pragma mark - Singleton

+ (nonnull instancetype)sharedInstance {
    static id sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        sharedInstance = [[self alloc] init];

        NSSetUncaughtExceptionHandler(&NOCExceptionHandler);
    });
    return sharedInstance;
}

#pragma mark - NSObject overrides

- (nonnull instancetype)init {
    if ((self = [super init])) {
        _lenDelimiter = (NSUInteger)80;
    }
    return self;
}

#pragma mark - Log output

+ (void)log:(NOCLogLevel)level
       type:(NOCLogType)type
       file:(nullable const char *)file
       line:(NSUInteger)line
     thread:(nullable NSString *)thread
     object:(nullable NSString *)object
   function:(nullable const char *)function
     format:(nullable NSString *)format, ... {
    if ((NSUInteger)type > (NSUInteger)level || !format) return;

    NSString *message = [NSString alloc];
    va_list args;
    va_start(args, format);
    message = [message initWithFormat:format arguments:args];
    va_end(args);

    [[self sharedInstance] log:message
                          type:type
                          file:file
                          line:line
                        thread:thread
                        object:object
                      function:function];
}

#pragma mark - Private methods - Log output

- (void)log:(nullable NSString *)message
       type:(NOCLogType)type
       file:(nullable const char *)file
       line:(NSUInteger)line
     thread:(nullable NSString *)thread
     object:(nullable NSString *)object
   function:(nullable const char *)function {
    NSString *msg = [self message:message
                             type:type
                             file:file
                             line:line
                           thread:thread
                           object:object
                         function:function];
    if (!msg || msg.length < (NSUInteger)1) return;

    if (type == NOCLogTypeError || type == NOCLogTypeWarn) {
        printf("\n");
        NSLog(@"%s", [msg UTF8String]);
    }
    else {
        printf("%s", [msg UTF8String]);
    }
}

#pragma mark - Private methods - Log message

- (nullable NSString *)message:(nullable NSString *)message
                          type:(NOCLogType)type
                          file:(nullable const char *)file
                          line:(NSUInteger)line
                        thread:(nullable NSString *)thread
                        object:(nullable NSString *)object
                      function:(nullable const char *)function {
    NSString *res = [NSString alloc];

    if (type != NOCLogTypeInfo) {
        res = @"[NOCLog] -";
        switch (type) {
            case NOCLogTypeError:
                res = [res stringByAppendingString:@" Error "];
                break;
            case NOCLogTypeWarn:
                res = [res stringByAppendingString:@" Warning "];
                break;
            case NOCLogTypeDebug:
                res = [res stringByAppendingString:@" Debug "];
                break;
            case NOCLogTypeVerbose:
                res = [res stringByAppendingString:@" Verbose "];
                break;
            default:
                break;
        }

        NSString *del = [@"" stringByPaddingToLength:_lenDelimiter
                                          withString:@"-"
                                     startingAtIndex:(NSUInteger)0];
        NSString *frm = @"";
        NSInteger len = (NSInteger)_lenDelimiter - (NSInteger)res.length;
        len = len < (NSInteger)0 ? (NSInteger)0 : len;
        res = [res stringByAppendingString:[del substringToIndex:(NSUInteger)len]];
        res = [res stringByAppendingString:@"\n"];

        if (thread && thread.length > (NSUInteger)0) {
            frm = @"%@- Thread   : %@\n";
            res = [NSString stringWithFormat:frm, res, thread];
        }
        if (object && object.length > (NSUInteger)0) {
            frm = @"%@- Object   : %@\n";
            res = [NSString stringWithFormat:frm, res, object];
        }
        NSString *func = [NSString stringWithUTF8String:function];
        if (func && func.length > (NSUInteger)0) {
            frm = @"%@- Function : %@\n";
            res = [NSString stringWithFormat:frm, res, func];
        }
        NSString *filename = [[NSString stringWithUTF8String:file]
                              lastPathComponent];
        if (filename && filename.length > (NSUInteger)0) {
            frm = @"%@- File     : %@ (%d line)\n";
            res = [NSString stringWithFormat:frm, res, filename, line];
        }

        frm = @"\n%@%@";
        res = [NSString stringWithFormat:frm, res, del];

        if (message && message.length > (NSUInteger)0) {
            frm = @"%@\n%@\n%@\n";
            res = [NSString stringWithFormat:frm, res, message, del];
        }
        else {
            frm = @"%@\n";
            res = [NSString stringWithFormat:frm, res];
        }
    }
    else {
        if (message && message.length > (NSUInteger)0) {
            res = [NSString stringWithFormat:@"\n%@\n", message];
        }
    }

    return res;
}

@end
