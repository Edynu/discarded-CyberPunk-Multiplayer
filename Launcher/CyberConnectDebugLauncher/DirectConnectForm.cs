using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System;
using System.Diagnostics;
using System.IO.Pipes;
using System.Text;
using System.Threading;
using System.Windows.Forms;

namespace CyberConnectDebugLauncher
{
    public partial class DirectConnectForm : Form
    {
        private const string PipeName = "CyberConnectPipe";
        private string gameFolderPath = "";
        private bool MessageSend = false;
        public DirectConnectForm(string gameFolderPath)
        {
            InitializeComponent();
            this.gameFolderPath = gameFolderPath;
        }

        private void closeButton_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void connectButton_Click(object sender, EventArgs e)
        {

            LaunchGame();
        }

        private void LaunchGame()
        {
            string gameExecutablePath = Path.Combine(gameFolderPath, "bin", "x64", "Cyberpunk2077.exe");

            if (File.Exists(gameExecutablePath))
            {
                // Start the game
                Process.Start(gameExecutablePath);

                // Wait for the game to launch
                WaitForGameToLaunch();

                // Send a message to the DLL indicating that the game has launched
                string ip = ipTextBox.Text;
                string port = portText.Text;

                // Send the IP address and port information to the DLL
                SendMessage($"{ip}:{port}");

            }
            else
            {
                MessageBox.Show("Game executable not found!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void WaitForGameToLaunch()
        {
            // Polling loop to check if the game process is running
            while (true)
            {
                // Check if the game process is running
                if (Process.GetProcessesByName("Cyberpunk2077").Length > 0)
                {
                    break;
                }

                // Wait for a short interval before checking again
                Thread.Sleep(1000);
            }
        }


        private void SendMessage(string message)
        {
            NamedPipeClientStream pipeClient = null;
            try
            {
                using (pipeClient = new NamedPipeClientStream(".", PipeName, PipeDirection.Out))
                {
                    // Connect to the pipe
                    pipeClient.Connect();

                    // Write the message to the pipe
                    byte[] buffer = Encoding.Unicode.GetBytes(message); // UTF-16LE encoding
                    pipeClient.Write(buffer, 0, buffer.Length);

                    // Close the pipe
                    pipeClient.Close();


                }
            }
            catch (Exception ex)
            {
                MessageBox.Show($"Error sending message: {ex.Message}", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
            finally
            {
                Application.Exit();
            }

        }
    }
}
