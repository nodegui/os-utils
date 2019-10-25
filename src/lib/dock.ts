import addon from "./utils/addon";

export class Dock {
  native = new addon.Dock();
  show() {
    this.native.show();
  }
  hide() {
    this.native.hide();
  }
}
