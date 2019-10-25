import { Dock } from "./lib/dock";

Dock.show();

setTimeout(() => {
  console.log("Hiding the Dock");
  Dock.hide();
}, 2000);
