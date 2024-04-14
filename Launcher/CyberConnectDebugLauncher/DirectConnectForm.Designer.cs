namespace CyberConnectDebugLauncher
{
    partial class DirectConnectForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            ipTextBox = new TextBox();
            serverListLabel = new Label();
            label1 = new Label();
            label2 = new Label();
            portText = new TextBox();
            connectButton = new Button();
            closeButton = new Button();
            SuspendLayout();
            // 
            // ipTextBox
            // 
            ipTextBox.BackColor = Color.FromArgb(41, 44, 51);
            ipTextBox.Font = new Font("Cascadia Mono SemiBold", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            ipTextBox.ForeColor = Color.FromArgb(62, 120, 138);
            ipTextBox.Location = new Point(48, 49);
            ipTextBox.Name = "ipTextBox";
            ipTextBox.Size = new Size(221, 31);
            ipTextBox.TabIndex = 0;
            ipTextBox.Text = "127.0.0.1";
            ipTextBox.TextAlign = HorizontalAlignment.Center;
            // 
            // serverListLabel
            // 
            serverListLabel.Anchor = AnchorStyles.Top;
            serverListLabel.AutoSize = true;
            serverListLabel.Font = new Font("Cascadia Mono", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            serverListLabel.ForeColor = Color.FromArgb(62, 120, 138);
            serverListLabel.Location = new Point(2, 48);
            serverListLabel.Name = "serverListLabel";
            serverListLabel.Size = new Size(52, 30);
            serverListLabel.TabIndex = 2;
            serverListLabel.Text = "IP:";
            // 
            // label1
            // 
            label1.Anchor = AnchorStyles.Top;
            label1.AutoSize = true;
            label1.Font = new Font("Cascadia Mono", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label1.ForeColor = Color.FromArgb(62, 120, 138);
            label1.Location = new Point(2, 1);
            label1.Name = "label1";
            label1.Size = new Size(195, 30);
            label1.TabIndex = 3;
            label1.Text = "Direct Connect";
            // 
            // label2
            // 
            label2.Anchor = AnchorStyles.Top;
            label2.AutoSize = true;
            label2.Font = new Font("Cascadia Mono", 13.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            label2.ForeColor = Color.FromArgb(62, 120, 138);
            label2.Location = new Point(275, 49);
            label2.Name = "label2";
            label2.Size = new Size(78, 30);
            label2.TabIndex = 4;
            label2.Text = "Port:";
            // 
            // portText
            // 
            portText.BackColor = Color.FromArgb(41, 44, 51);
            portText.Font = new Font("Cascadia Mono SemiBold", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            portText.ForeColor = Color.FromArgb(62, 120, 138);
            portText.Location = new Point(359, 49);
            portText.Name = "portText";
            portText.Size = new Size(121, 31);
            portText.TabIndex = 5;
            portText.Text = "40000";
            portText.TextAlign = HorizontalAlignment.Center;
            // 
            // connectButton
            // 
            connectButton.FlatStyle = FlatStyle.Flat;
            connectButton.Font = new Font("Cascadia Mono", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            connectButton.ForeColor = Color.FromArgb(62, 120, 138);
            connectButton.Location = new Point(174, 98);
            connectButton.Margin = new Padding(3, 0, 3, 3);
            connectButton.Name = "connectButton";
            connectButton.Size = new Size(140, 43);
            connectButton.TabIndex = 6;
            connectButton.Text = "Connect";
            connectButton.TextAlign = ContentAlignment.TopCenter;
            connectButton.UseVisualStyleBackColor = true;
            connectButton.Click += connectButton_Click;
            // 
            // closeButton
            // 
            closeButton.FlatAppearance.BorderSize = 0;
            closeButton.FlatStyle = FlatStyle.Flat;
            closeButton.Font = new Font("Cascadia Mono", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            closeButton.ForeColor = Color.FromArgb(62, 120, 138);
            closeButton.Location = new Point(450, -2);
            closeButton.Name = "closeButton";
            closeButton.Size = new Size(39, 38);
            closeButton.TabIndex = 7;
            closeButton.Text = "X";
            closeButton.UseVisualStyleBackColor = true;
            closeButton.Click += closeButton_Click;
            // 
            // DirectConnectForm
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            BackColor = Color.FromArgb(41, 44, 48);
            ClientSize = new Size(482, 153);
            Controls.Add(closeButton);
            Controls.Add(connectButton);
            Controls.Add(portText);
            Controls.Add(label2);
            Controls.Add(label1);
            Controls.Add(serverListLabel);
            Controls.Add(ipTextBox);
            FormBorderStyle = FormBorderStyle.None;
            Name = "DirectConnectForm";
            ShowInTaskbar = false;
            StartPosition = FormStartPosition.CenterParent;
            Text = "DirectConnectForm";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TextBox ipTextBox;
        private Label serverListLabel;
        private Label label1;
        private Label label2;
        private TextBox portText;
        private Button connectButton;
        private Button closeButton;
    }
}