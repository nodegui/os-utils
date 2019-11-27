# os-utils

[![npm version](https://img.shields.io/npm/v/@nodegui/os-utils.svg)](https://www.npmjs.com/package/@nodegui/os-utils)

A helper module which contains OS specific native features.

## Installation

```
npm install @nodegui/os-utils
```

## Usage

```js
import { Dock } from "@nodegui/os-utils";

console.log("Showing the Dock icon on macOS");
Dock.show();
console.log("Hiding the Dock icon on macOS");
Dock.hide();
```

```js
import { AboutPanel } from "@nodegui/os-utils";

console.log("Open the about panel on macOS");
AboutPanel.open();
console.log("Open the about panel on macOS with modified defaults");
AboutPanel.open({ name: "Custom name", version: "2.3.5" });
```

```js
import { Info } from "@nodegui/os-utils";

console.log("isDarkMode: " + Info.isDarkMode());
```

## Supported APIs

### macOS

- Dock

  - `show()` - static method - Shows the Dock icon on macOS. Does nothing on other platforms.
  - `hide()` - static method - Hides the Dock icon on macOS. Does nothing on other platforms.

- AboutPanel

  - `open(options?: object)` - static method - Opens the about panel on macOS. Does nothing on other platforms. `options` is optional and can contain the following strings: `name`, `version`, `applicationVersion`, and `copyright`. The default values are derived from `Info.plist`.

- Info
  - `isDarkMode` - static method - Checks if the OS theme is dark mode in macOS. Does nothing on other platforms and returns false. Returns a boolean.

## License

MIT
