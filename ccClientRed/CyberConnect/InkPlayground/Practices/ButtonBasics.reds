
module InkPlayground.Practices
import InkPlayground.Workbench.Practice
import Codeware.UI.*

public class ButtonBasics extends Practice {
	protected let m_top: wref<inkCompoundWidget>;

	protected let m_bottom: wref<inkCompoundWidget>;

	protected cb func OnCreate() -> Void {
		let root: ref<inkCanvas> = new inkCanvas();
		root.SetName(this.GetClassName());
		root.SetAnchor(inkEAnchor.Fill);
		
		let rows: ref<inkVerticalPanel> = new inkVerticalPanel();
		rows.SetName(n"rows");
		rows.SetFitToContent(true);
		rows.SetAnchor(inkEAnchor.BottomCenter);
		rows.SetAnchorPoint(new Vector2(0.5, 2));
		rows.SetChildMargin(new inkMargin(0.0, 0.0, 0.0, 30.0));
		rows.Reparent(root);

		let top: ref<inkHorizontalPanel> = new inkHorizontalPanel();
		top.SetFitToContent(true);
		top.SetHAlign(inkEHorizontalAlign.Center);
		top.SetChildMargin(new inkMargin(20.0, 0.0, 20.0, 0.0));
		top.Reparent(rows);

		let bottom: ref<inkHorizontalPanel> = new inkHorizontalPanel();
		bottom.SetFitToContent(true);
		bottom.SetHAlign(inkEHorizontalAlign.Center);
		bottom.SetChildMargin(new inkMargin(20.0, 0.0, 20.0, 0.0));
		bottom.Reparent(rows);

		let buttonHub: ref<HubButton> = HubButton.Create();
		buttonHub.SetName(n"HubButton");
		buttonHub.SetText(this.GetLocalizedText("InkPlayground-ButtonBasics-Button-Hub"));
		buttonHub.SetIcon(n"ico_deck_hub");
		buttonHub.ToggleAnimations(true);
		buttonHub.ToggleSounds(true);
		buttonHub.Reparent(top);

		this.m_top = top;
		this.m_bottom = bottom;

		this.SetRootWidget(root);
	}

	protected cb func OnInitialize() -> Void {
		this.RegisterListeners(this.m_top);
		this.RegisterListeners(this.m_bottom);
	}
	protected func RegisterListeners(container: wref<inkCompoundWidget>) -> Void {
		let childIndex: Int32 = 0;
		let numChildren: Int32 = container.GetNumChildren();

		while childIndex < numChildren {
			let widget: ref<inkWidget> = container.GetWidgetByIndex(childIndex);
			let button: ref<CustomButton> = widget.GetController() as CustomButton;

			if IsDefined(button) {
				button.RegisterToCallback(n"OnBtnClick", this, n"OnClick");
				button.RegisterToCallback(n"OnRelease", this, n"OnRelease");
				button.RegisterToCallback(n"OnEnter", this, n"OnEnter");
				button.RegisterToCallback(n"OnLeave", this, n"OnLeave");
			}

			childIndex += 1;
		}
	}

	protected cb func OnClick(widget: wref<inkWidget>) -> Bool {
		let button: ref<CustomButton> = widget.GetController() as CustomButton;

		let buttonName: String = button.GetText();
		let buttonEvent: String = this.GetLocalizedText("InkPlayground-ButtonBasics-Event-Click");

		this.Log("Checking client connection status");
		let isConnected = false;
		isConnected = 	ConnectionIsConnected();
		if (!isConnected) {
				this.Log("Connecting to the NET ");
				button.SetDisabled(!button.IsDisabled());
				startConnect("127.0.0.1", 2077);
			}
		else
		{
			button.SetDisabled(!button.IsDisabled());
			this.Log("Already Connected");
		}

		// if 	Equals(buttonName, "Connect")
		// {
		// 	startConnect("127.0.0.1", 2077);
		// 	//c.ConnectionConnect("127.0.0.1", 2077);
		// }

	}

	protected cb func OnRelease(evt: ref<inkPointerEvent>) -> Bool {
		let button: ref<CustomButton> = evt.GetTarget().GetController() as CustomButton;

		if evt.IsAction(n"popup_moveUp") {
			let buttonName: String = button.GetText();
			let buttonEvent: String = button.IsDisabled()
				? this.GetLocalizedText("InkPlayground-ButtonBasics-Event-Disable")
				: this.GetLocalizedText("InkPlayground-ButtonBasics-Event-Enable");

			this.Log(buttonName + ": " + buttonEvent);
			this.UpdateHints(button);

			this.PlaySound(n"MapPin", n"OnCreate");
		}
	}

	protected cb func OnEnter(evt: ref<inkPointerEvent>) -> Bool {
		let button: ref<CustomButton> = evt.GetTarget().GetController() as CustomButton;

		this.UpdateHints(button);
	}

	protected cb func OnLeave(evt: ref<inkPointerEvent>) -> Bool {
		this.RemoveHints();
	}

	protected func UpdateHints(button: ref<CustomButton>) -> Void {
		// this.UpdateHint(
		// 	n"popup_moveUp",
		// 	this.GetLocalizedText(
		// 		button.IsEnabled()
		// 			? "InkPlayground-ButtonBasics-Action-Disable"
		// 			: "InkPlayground-ButtonBasics-Action-Enable"
		// 	)
		// );

		this.UpdateHint(
			n"click",
			this.GetLocalizedText("InkPlayground-ButtonBasics-Action-Interact"),
			button.IsEnabled()
		);
	}

	protected func RemoveHints() -> Void {
		this.RemoveHint(n"popup_moveUp");
		this.RemoveHint(n"click");
	}
}
