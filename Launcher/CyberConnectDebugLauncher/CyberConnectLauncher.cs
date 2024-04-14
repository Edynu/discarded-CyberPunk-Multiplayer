namespace CyberConnectDebugLauncher
{
    public partial class CyberConnectLauncher : Form
    {

        private string gameFolderPath = "";
        public CyberConnectLauncher()
        {
            InitializeComponent();
            LoadGameFolderPath();
        }

        private void LoadGameFolderPath()
        {
            // Check if the configuration file exists
            if (File.Exists("config.txt"))
            {
                // Read the game folder path from the configuration file
                gameFolderPath = File.ReadAllText("config.txt");
            }
            else
            {
                // Prompt the user to select the game folder if the configuration file doesn't exist
                SelectGameFolder();
            }
        }

        private void SelectGameFolder()
        {
            // Display a folder browser dialog to select the game folder
            FolderBrowserDialog folderBrowserDialog = new FolderBrowserDialog();
            folderBrowserDialog.Description = "Select the Cyberpunk game folder";
            folderBrowserDialog.ShowNewFolderButton = false;

            if (folderBrowserDialog.ShowDialog() == DialogResult.OK)
            {
                // Save the selected game folder path to the configuration file
                gameFolderPath = folderBrowserDialog.SelectedPath;
                File.WriteAllText("config.txt", gameFolderPath);
            }
            else
            {
                // Exit the application if the user cancels the folder selection
                Application.Exit();
            }
        }

        private void exitButton_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void directConnect_Click(object sender, EventArgs e)
        {
            DirectConnectForm directConnectForm = new DirectConnectForm(gameFolderPath);

            // Show the DirectConnectForm as a modal dialog
            directConnectForm.ShowDialog();
        }

        private void refreshServerListButton_Click(object sender, EventArgs e)
        {

        }

        private void serverConnectButton_Click(object sender, EventArgs e)
        {

        }
    }
}
