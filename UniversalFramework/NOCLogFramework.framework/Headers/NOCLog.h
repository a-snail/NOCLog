#import <Foundation/Foundation.h>


#pragma mark -

/**
 A `NOCLogType` is an enumeration describing all **log types** used in the NOCLog library.

 Whether to outputs the log is determined by `NOCLogType` and `NOCLogLevel`.

 For example, if the **log type**(`NOCLogType`) of the log to be output is greater than the specified **log level**(`NOCLogLevel`), the log will not be output.
 */
typedef enum NOCLogType : NSUInteger {
    /**
     A `NOCLogTypeNone` is log type for no logs.
     */
    NOCLogTypeNone = 0,
    /**
     A `NOCLogTypeError` is log type for error logs.
     */
    NOCLogTypeError = 1 << 0,
    /**
     A `NOCLogTypeWarn` is log type for warning logs.
     */
    NOCLogTypeWarn = 1 << 1,
    /**
     A `NOCLogTypeInfo` is log type for information logs.
     */
    NOCLogTypeInfo = 1 << 2,
    /**
     A `NOCLogTypeDebug` is log type for debugging logs.

     If you use the debug log in each method, you can view the workflow.
     */
    NOCLogTypeDebug = 1 << 3,
    /**
     A `NOCLogTypeVerbose` is log type for verbose logs.
     */
    NOCLogTypeVerbose = 1 << 4
} /** */ NOCLogType;

/**
 A `NOCLogLevel` is an enumeration describing all **log levels** used in the NOCLog library.

 Whether to outputs the log is determined by `NOCLogType` and `NOCLogLevel`.

 For example, if the **log type**(`NOCLogType`) of the log to be output is greater than the specified **log level**(`NOCLogLevel`), the log will not be output.
 */
typedef enum NOCLogLevel : NSUInteger {
    /**
     A `NOCLogLevelOff` is log level at which no logs are output.

     At the `NOCLogLevelOff` log level, no logs are output.
     */
    NOCLogLevelOff = NOCLogTypeNone,
    /**
     A `NOCLogLevelError` is log level that error logs only available.

     At the `NOCLogLevelError` log level, only the error logs(`NOCLogTypeError`) are outputted.
     */
    NOCLogLevelError = NOCLogLevelOff | NOCLogTypeError,
    /**
     A `NOCLogLevelWarn` is log level that error logs and warning logs are available.

     At the `NOCLogLevelWarn` log level, the error logs(`NOCLogTypeError`) and the warning logs(`NOCLogTypeWarn`) are outputted.
     */
    NOCLogLevelWarn = NOCLogLevelError | NOCLogTypeWarn,
    /**
     A `NOCLogLevelInfo` is log level that error, warning and information logs are available.

     At the `NOCLogLevelInfo` log level, the error logs(`NOCLogTypeError`), the warning logs(`NOCLogTypeWarn`) and the information logs(`NOCLogTypeInfo`) are outputted.
     */
    NOCLogLevelInfo = NOCLogLevelWarn | NOCLogTypeInfo,
    /**
     A `NOCLogLevelDebug` is log level that error, warning, information and debugging logs are available.

     At the `NOCLogLevelDebug` log level, the error logs(`NOCLogTypeError`), the warning logs(`NOCLogTypeWarn`), the information logs(`NOCLogTypeInfo`) and the debugging logs are outputted.
     */
    NOCLogLevelDebug = NOCLogLevelInfo | NOCLogTypeDebug,
    /**
     A `NOCLogLevelVerbose` is log level that all logs are available.

     At the ``NOCLogLevelVerbose` log level, all logs are outputted.
     */
    NOCLogLevelVerbose = NOCLogLevelDebug | NOCLogTypeVerbose,
    /**
     A `NOCLogLevelAll` is log level that all logs are available.

     At the ``NOCLogLevelAll` log level, all logs are outputted.
     */
    NOCLogLevelAll = NSUIntegerMax
} /** */ NOCLogLevel;


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

/**
 `NOCLog` class provides console log output features for debugging.

 Whether to outputs the log is determined by `NOCLogType` and `NOCLogLevel`.

 For example, if the **log type**(`NOCLogType`) of the log to be output is greater than the specified **log level**(`NOCLogLevel`), the log will not be output.


 ### **LOGLEVEL**
 The log output level(`NOCLogLevel`) of the NOCLog library can be specified using the `LOGLEVEL` macro.

 The `LOGLEVEL` macro can be specified in the following ways.

 If you set the value of `LOGLEVEL` in the **Preprocessor Macros** of the Project **Build Settings**, uses the `LOGLEVEL` value of the **Preprocessor Macros** as the log output level(`NOCLogLevel`).

 ```objective-c
 LOGLEVEL=7
 ```

 If the `LOGLEVEL` value is not specified in the **Preprocessor Macros** in the **Build Settings**, define the `LOGLEVEL` macro(using the `#define`) before importing the NOCLog library(using the `#import`).
 The defined `LOGLEVEL` value(using the `#define`) is used as the log output level(`NOCLogLevel`).

 ```objective-c
 #define LOGLEVEL 7
 #import <NOCLogFramework/NOCLog.h>
 ```

 @note If you do not define the `LOGLEVEL` macro, it defaults to `NOCLogLevelWarn`(= **3**).

 ## Log output macro functions

 You can output the log using the + [NOCLog log:type:file:line:thread:object:function:format:]` method.
 However, it may be inconvenient to use because there are a lot of method parameters.

 The following macro functions are defined so that the log output of the NOCLog library can be easily used.

 ### **NOCLogE(fmt, ...)**
 Use the `NOCLogE` macro function to output the error logs.

 ```objective-c
 NOCLogE(@"%@", @"Error log!");
 ```

 ### **NOCLogW(fmt, ...)**
 Use the `NOCLogW` macro function to output the warning logs.

 ```objective-c
 NOCLogW(@"%@", @"Warning log!");
 ```

 ### **NOCLogI(fmt, ...)**
 Use the `NOCLogI` macro function to output the information logs.

 ```objective-c
 NOCLogI(@"%@", @"Information log!");
 ```

 ### **NOCLogD(fmt, ...)**
 Use the `NOCLogD` macro function to output the debugging logs.

 ```objective-c
 NOCLogD(@"%@", @"Debug log!");
 ```

 ### **NOCLogV(fmt, ...)**
 Use the `NOCLogV` macro function to output the verbose logs.

 ```objective-c
 NOCLogV(@"%@", @"Verbose log!");
 ```
 */
@interface NOCLog : NSObject

#pragma mark - Singleton

/**
 Singleton instance object of the `NOCLog` class.
 */
@property (readonly, strong, nonatomic, nonnull, class) NOCLog *sharedInstance;

#pragma mark - Log output

/**
 Outputs the console log using the passed arguments.

 @param level
 The log level(`NOCLogLevel`) that determines whether to log output.
 @param type
 The log type(`NOCLogType`) of the log to outputs.
 @param file
 The file name of the file that called the log output function.
 @param line
 The line number of the code that called the log output function.
 @param thread
 The thread that called the log output function.
 @param object
 The object that called the log output function.
 @param function
 The function name of the function that contains the code that called the log output function.
 @param format
 The output format of the log message to output.
 */
+ (void)log:(NOCLogLevel)level
       type:(NOCLogType)type
       file:(nullable const char *)file
       line:(NSUInteger)line
     thread:(nullable NSString *)thread
     object:(nullable NSString *)object
   function:(nullable const char *)function
format:(nullable NSString *)format, ... NS_FORMAT_FUNCTION(8, 9);

@end
