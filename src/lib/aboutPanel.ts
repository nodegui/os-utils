import addon from "./utils/addon";

interface IOptions {
  name?: string
  version?: string
  applicationVersion?: string
  copyright?: string
}

export class AboutPanel {
  static open(options: IOptions = {}) {
    addon.AboutPanel.open(options)
  }
}
