#import <AppKit/AppKit.h>
#include "dock.h"

void Dock::show() {
  [NSApp setActivationPolicy:NSApplicationActivationPolicyRegular];
}

void Dock::hide() {
  [NSApp setActivationPolicy:NSApplicationActivationPolicyAccessory];
}