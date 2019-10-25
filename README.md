# nodegui-os-utils

A nodegui helper module which will contain OS specific native features which Qt doesnt support and hence requires native code in respective operting systems.

# Installation

```
npm install @nodegui/nodegui-os-utils
```

# Usage

```js
import { Dock } from "@nodegui/nodegui-os-utils";

console.log("Showing the Dock Icon on MacOS");
Dock.show();
console.log("Hiding the Dock Icon on MacOS");
Dock.hide();
```

# Supported APIs

## MacOS

- Dock
  - `show()` - static method - Shows the dock icon of the nodegui app on macos. Noop on other platforms.
  - `hide()` - static method - Hides the dock icon of the nodegui app on macos. Noop on other platforms.

# License

MIT
