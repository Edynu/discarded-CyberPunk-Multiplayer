module InkPlayground.Localization.Packages
import Codeware.Localization.*

public class English extends ModLocalizationPackage {
	protected func DefineTexts() -> Void {
		this.Text("InkPlayground-Action-Label", "CyberConnect");

		this.Text("InkPlayground-Popup-Title", "CyberConnect");
		this.Text("InkPlayground-Popup-Fluff-Right", "Martinez Diary");
		this.Text("InkPlayground-Popup-Fluff-Bottom",
			"Version 0.0.0.0.0.0.0.0.2\n" +
			"Edynu, TayFun\n" +
			"Fuck FiveM.");

		this.Text("InkPlayground-ButtonBasics-Event-Ready", "All buttons are ready");
		this.Text("InkPlayground-ButtonBasics-Event-Click", "Click");
		this.Text("InkPlayground-ButtonBasics-Event-Enable", "Enable");
		this.Text("InkPlayground-ButtonBasics-Event-Disable", "Disable");
		this.Text("InkPlayground-ButtonBasics-Button-Left", "Button L");
		this.Text("InkPlayground-ButtonBasics-Button-Right", "Button R");
		this.Text("InkPlayground-ButtonBasics-Button-Hub", "Connect");
		this.Text("InkPlayground-ButtonBasics-Action-Interact", "Interact");
		this.Text("InkPlayground-ButtonBasics-Action-Enable", "Enable");
		this.Text("InkPlayground-ButtonBasics-Action-Disable", "Disable");

		this.Text("InkPlayground-ColorPalette-Event-Ready", "Palette created");

		this.Text("InkPlayground-CursorState-Event-Ready", "Cursor tracking started");


		this.Text("InkPlayground-InputText-Event-Ready", "IP Input");
		this.Text("InkPlayground-InputText-Input-Label", "IP Adress");
	}
}
