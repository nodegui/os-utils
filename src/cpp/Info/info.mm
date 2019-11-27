#import <AppKit/AppKit.h>
#include "info.h"

bool Info::isDarkMode() {
  NSString *darkModeMode = @"Dark";
  NSString *osxMode = [[NSUserDefaults standardUserDefaults] stringForKey:@"AppleInterfaceStyle"];
  // check here if dark mode;
  return [darkModeMode isEqualToString:osxMode];
}
