#import <Foundation/Foundation.h>


#pragma mark -

typedef enum NOCLogType : NSUInteger {
    NOCLogTypeNone    = 0,
    NOCLogTypeError   = 1 << 0,
    NOCLogTypeWarn    = 1 << 1,
    NOCLogTypeInfo    = 1 << 2,
    NOCLogTypeDebug   = 1 << 3,
    NOCLogTypeVerbose = 1 << 4
} NOCLogType;

typedef enum NOCLogLevel : NSUInteger {
    NOCLogLevelOff     = NOCLogTypeNone,
    NOCLogLevelError   = NOCLogLevelOff   | NOCLogTypeError,
    NOCLogLevelWarn    = NOCLogLevelError | NOCLogTypeWarn,
    NOCLogLevelInfo    = NOCLogLevelWarn  | NOCLogTypeInfo,
    NOCLogLevelDebug   = NOCLogLevelInfo  | NOCLogTypeDebug,
    NOCLogLevelVerbose = NOCLogLevelDebug | NOCLogTypeVerbose,
    NOCLogLevelAll = NSUIntegerMax
} NOCLogLevel;


#pragma mark -

#ifndef LOGLEVEL
#define LOGLEVEL NOCLogLevelWarn
#endif

#define __NOC_O__ [NSString stringWithFormat:@"%@", (self ? self : @"")]

#define __NOC_T__ [NSString stringWithFormat:@"%@", [NSThread currentThread]]

#define NOCLogE(fmt, ...)               \
        [NOCLog log:LOGLEVEL            \
               type:NOCLogTypeError     \
               file:__FILE__            \
               line:__LINE__            \
             thread:__NOC_T__           \
             object:__NOC_O__           \
           function:__PRETTY_FUNCTION__ \
             format:fmt, ##__VA_ARGS__]

#define NOCLogW(fmt, ...)               \
        [NOCLog log:LOGLEVEL            \
               type:NOCLogTypeWarn      \
               file:__FILE__            \
               line:__LINE__            \
             thread:__NOC_T__           \
             object:__NOC_O__           \
           function:__PRETTY_FUNCTION__ \
             format:fmt, ##__VA_ARGS__]

#define NOCLogI(fmt, ...)               \
        [NOCLog log:LOGLEVEL            \
               type:NOCLogTypeInfo      \
               file:__FILE__            \
               line:__LINE__            \
             thread:__NOC_T__           \
             object:__NOC_O__           \
           function:__PRETTY_FUNCTION__ \
             format:fmt, ##__VA_ARGS__]

#define NOCLogD(fmt, ...)               \
        [NOCLog log:LOGLEVEL            \
               type:NOCLogTypeDebug     \
               file:__FILE__            \
               line:__LINE__            \
             thread:__NOC_T__           \
             object:__NOC_O__           \
           function:__PRETTY_FUNCTION__ \
             format:fmt, ##__VA_ARGS__]

#define NOCLogV(fmt, ...)               \
        [NOCLog log:LOGLEVEL            \
               type:NOCLogTypeVerbose   \
               file:__FILE__            \
               line:__LINE__            \
             thread:__NOC_T__           \
             object:__NOC_O__           \
           function:__PRETTY_FUNCTION__ \
             format:fmt, ##__VA_ARGS__]


#pragma mark -

@interface NOCLog : NSObject

#pragma mark - Singleton

@property (readonly, strong, nonatomic, nonnull, class) NOCLog *sharedInstance;

#pragma mark - Log output

+ (void)log:(NOCLogLevel)level
       type:(NOCLogType)type
       file:(nullable const char *)file
       line:(NSUInteger)line
     thread:(nullable NSString *)thread
     object:(nullable NSString *)object
   function:(nullable const char *)function
format:(nullable NSString *)format, ... NS_FORMAT_FUNCTION(8, 9);

@end
