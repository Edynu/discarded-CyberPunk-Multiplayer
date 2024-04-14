namespace CyberConnectDebugLauncher
{
    partial class CyberConnectLauncher
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            panel1 = new Panel();
            directConnect = new Button();
            refreshServerListButton = new Button();
            panel3 = new Panel();
            headerLabel = new Label();
            serverListLabel = new Label();
            panel2 = new Panel();
            credits = new Label();
            panel4 = new Panel();
            panel6 = new Panel();
            exitButton = new Button();
            panel5 = new Panel();
            serverConnectButton = new Button();
            serverInfoLabel = new Label();
            panel1.SuspendLayout();
            panel3.SuspendLayout();
            panel2.SuspendLayout();
            panel4.SuspendLayout();
            panel6.SuspendLayout();
            panel5.SuspendLayout();
            SuspendLayout();
            // 
            // panel1
            // 
            panel1.BackColor = Color.FromArgb(41, 44, 51);
            panel1.BorderStyle = BorderStyle.FixedSingle;
            panel1.Controls.Add(directConnect);
            panel1.Controls.Add(refreshServerListButton);
            panel1.Controls.Add(panel3);
            panel1.Dock = DockStyle.Left;
            panel1.Location = new Point(0, 0);
            panel1.Name = "panel1";
            panel1.Size = new Size(285, 720);
            panel1.TabIndex = 0;
            // 
            // directConnect
            // 
            directConnect.FlatStyle = FlatStyle.Flat;
            directConnect.Location = new Point(12, 218);
            directConnect.Name = "directConnect";
            directConnect.Size = new Size(260, 41);
            directConnect.TabIndex = 2;
            directConnect.Text = "Direct Connect";
            directConnect.UseVisualStyleBackColor = true;
            directConnect.Click += directConnect_Click;
            // 
            // refreshServerListButton
            // 
            refreshServerListButton.FlatStyle = FlatStyle.Flat;
            refreshServerListButton.Location = new Point(12, 161);
            refreshServerListButton.Name = "refreshServerListButton";
            refreshServerListButton.Size = new Size(260, 41);
            refreshServerListButton.TabIndex = 1;
            refreshServerListButton.Text = "Refresh Servers";
            refreshServerListButton.UseVisualStyleBackColor = true;
            refreshServerListButton.Click += refreshServerListButton_Click;
            // 
            // panel3
            // 
            panel3.BackColor = Color.FromArgb(192, 192, 10);
            panel3.Controls.Add(headerLabel);
            panel3.Dock = DockStyle.Top;
            panel3.Location = new Point(0, 0);
            panel3.Name = "panel3";
            panel3.Size = new Size(283, 68);
            panel3.TabIndex = 0;
            // 
            // headerLabel
            // 
            headerLabel.AutoSize = true;
            headerLabel.FlatStyle = FlatStyle.Flat;
            headerLabel.Font = new Font("Cascadia Mono", 19.8000011F, FontStyle.Bold, GraphicsUnit.Point, 0);
            headerLabel.ForeColor = Color.FromArgb(64, 64, 64);
            headerLabel.Location = new Point(12, 9);
            headerLabel.Name = "headerLabel";
            headerLabel.Size = new Size(260, 45);
            headerLabel.TabIndex = 0;
            headerLabel.Text = "CyberConnect";
            // 
            // serverListLabel
            // 
            serverListLabel.Anchor = AnchorStyles.Top;
            serverListLabel.AutoSize = true;
            serverListLabel.Font = new Font("Cascadia Mono SemiBold", 10.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            serverListLabel.Location = new Point(427, 82);
            serverListLabel.Name = "serverListLabel";
            serverListLabel.Size = new Size(120, 22);
            serverListLabel.TabIndex = 1;
            serverListLabel.Text = "Server List";
            // 
            // panel2
            // 
            panel2.BackColor = Color.FromArgb(30, 32, 36);
            panel2.BorderStyle = BorderStyle.FixedSingle;
            panel2.Controls.Add(credits);
            panel2.Dock = DockStyle.Bottom;
            panel2.Location = new Point(285, 690);
            panel2.Name = "panel2";
            panel2.Size = new Size(995, 30);
            panel2.TabIndex = 1;
            // 
            // credits
            // 
            credits.AutoSize = true;
            credits.Font = new Font("Cascadia Mono SemiBold", 7.8F, FontStyle.Bold, GraphicsUnit.Point, 0);
            credits.Location = new Point(653, 2);
            credits.Name = "credits";
            credits.Size = new Size(336, 17);
            credits.TabIndex = 0;
            credits.Text = "CyberConnect created by idiot named Edynu";
            // 
            // panel4
            // 
            panel4.BorderStyle = BorderStyle.FixedSingle;
            panel4.Controls.Add(serverListLabel);
            panel4.Controls.Add(panel6);
            panel4.Controls.Add(panel5);
            panel4.Dock = DockStyle.Fill;
            panel4.Location = new Point(285, 0);
            panel4.Name = "panel4";
            panel4.Size = new Size(995, 690);
            panel4.TabIndex = 2;
            // 
            // panel6
            // 
            panel6.BackColor = Color.FromArgb(30, 32, 36);
            panel6.BorderStyle = BorderStyle.FixedSingle;
            panel6.Controls.Add(exitButton);
            panel6.Dock = DockStyle.Top;
            panel6.Location = new Point(0, 0);
            panel6.Name = "panel6";
            panel6.Size = new Size(993, 68);
            panel6.TabIndex = 1;
            // 
            // exitButton
            // 
            exitButton.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            exitButton.FlatAppearance.BorderSize = 0;
            exitButton.FlatStyle = FlatStyle.Flat;
            exitButton.Location = new Point(956, 3);
            exitButton.Name = "exitButton";
            exitButton.Size = new Size(32, 32);
            exitButton.TabIndex = 0;
            exitButton.Text = "X";
            exitButton.UseVisualStyleBackColor = true;
            exitButton.Click += exitButton_Click;
            // 
            // panel5
            // 
            panel5.BackColor = Color.FromArgb(41, 44, 51);
            panel5.BorderStyle = BorderStyle.FixedSingle;
            panel5.Controls.Add(serverConnectButton);
            panel5.Controls.Add(serverInfoLabel);
            panel5.Dock = DockStyle.Bottom;
            panel5.Location = new Point(0, 504);
            panel5.Name = "panel5";
            panel5.Size = new Size(993, 184);
            panel5.TabIndex = 0;
            // 
            // serverConnectButton
            // 
            serverConnectButton.FlatStyle = FlatStyle.Flat;
            serverConnectButton.Location = new Point(864, 126);
            serverConnectButton.Name = "serverConnectButton";
            serverConnectButton.Size = new Size(117, 41);
            serverConnectButton.TabIndex = 3;
            serverConnectButton.Text = "Connect";
            serverConnectButton.UseVisualStyleBackColor = true;
            serverConnectButton.Visible = false;
            serverConnectButton.Click += serverConnectButton_Click;
            // 
            // serverInfoLabel
            // 
            serverInfoLabel.Anchor = AnchorStyles.Top;
            serverInfoLabel.AutoSize = true;
            serverInfoLabel.Font = new Font("Cascadia Mono SemiBold", 10.2F, FontStyle.Bold, GraphicsUnit.Point, 0);
            serverInfoLabel.Location = new Point(441, 10);
            serverInfoLabel.Name = "serverInfoLabel";
            serverInfoLabel.Size = new Size(120, 22);
            serverInfoLabel.TabIndex = 2;
            serverInfoLabel.Text = "Server Info";
            // 
            // Form1
            // 
            AutoScaleMode = AutoScaleMode.None;
            BackColor = Color.FromArgb(41, 44, 51);
            ClientSize = new Size(1280, 720);
            Controls.Add(panel4);
            Controls.Add(panel2);
            Controls.Add(panel1);
            Font = new Font("Cascadia Mono", 12F, FontStyle.Regular, GraphicsUnit.Point, 0);
            ForeColor = Color.FromArgb(62, 120, 138);
            FormBorderStyle = FormBorderStyle.None;
            Name = "Form1";
            StartPosition = FormStartPosition.CenterScreen;
            Text = "Form1";
            panel1.ResumeLayout(false);
            panel3.ResumeLayout(false);
            panel3.PerformLayout();
            panel2.ResumeLayout(false);
            panel2.PerformLayout();
            panel4.ResumeLayout(false);
            panel4.PerformLayout();
            panel6.ResumeLayout(false);
            panel5.ResumeLayout(false);
            panel5.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private Panel panel1;
        private Panel panel3;
        private Label serverListLabel;
        private Label headerLabel;
        private Panel panel2;
        private Panel panel4;
        private Panel panel5;
        private Panel panel6;
        private Button exitButton;
        private Button refreshServerListButton;
        private Button directConnect;
        private Label credits;
        private Label serverInfoLabel;
        private Button serverConnectButton;
    }
}
