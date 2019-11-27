import React from "react";
import { render } from "ink";
import SelectInput from "ink-select-input";

import { Info, Dock, AboutPanel } from "./index";

const Demo = () => {
  const handleSelect = (item: any) => {
    switch (item.value) {
      case "hideDock":
        Dock.hide();
        break;
      case "showDock":
        Dock.show();
        break;
      case "openDefaultAbout":
        AboutPanel.open();
        break;
      case "openCustomAbout":
        AboutPanel.open({
          name: "NodeGUI OS utils",
          copyright: "Copyright © NodeGUI 2019",
          version: "78.0",
          applicationVersion: "78.0.3904.70"
        });
        break;
      case "isDarkMode":
        console.log(Info.isDarkMode());
        break;
    }
  };

  const items = [
    {
      label: "Hide dock icon",
      value: "hideDock"
    },
    {
      label: "Show dock icon",
      value: "showDock"
    },
    {
      label: "Open default about window",
      value: "openDefaultAbout"
    },
    {
      label: "Open custom about window",
      value: "openCustomAbout"
    },
    {
      label: "Check if dark mode",
      value: "isDarkMode"
    }
  ];

  return <SelectInput items={items} onSelect={handleSelect} />;
};

render(<Demo />);
