#import <AppKit/AppKit.h>
#include "about_panel.h"

void AboutPanel::open(AboutPanel::options options) {
  NSMutableDictionary *dictionary = [NSMutableDictionary new];
  if (!options.name.empty()) {
    [dictionary setObject:[NSString stringWithUTF8String:options.name.c_str()] forKey:NSAboutPanelOptionApplicationName];
  }
  if (!options.copyright.empty()) {
    [dictionary setObject:[NSString stringWithUTF8String:options.copyright.c_str()] forKey:@"Copyright"];
  }
  if (!options.version.empty()) {
    [dictionary setObject:[NSString stringWithUTF8String:options.version.c_str()] forKey:NSAboutPanelOptionVersion];
  }
  if (!options.applicationVersion.empty()) {
    [dictionary setObject:[NSString stringWithUTF8String:options.applicationVersion.c_str()] forKey:NSAboutPanelOptionApplicationVersion];
  }
  [[NSApplication sharedApplication] orderFrontStandardAboutPanelWithOptions:dictionary];
}
