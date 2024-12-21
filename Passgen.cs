
using System;
using System.IO;
using System.Text;

class Passgen
{
    static void Main()
    {

        // By changing this, the storage file for passwords will be renamed to the designated name.
        string filename = "passlog.txt";


        Console.Write("Enter password name: ");
        string name = Console.ReadLine();

        Console.Write("Enter password length: ");
        if (!int.TryParse(Console.ReadLine(), out int length) || length <= 0)
        {
            Console.WriteLine("Invalid length");
            return;
        }

        
        EnsureFileExists(filename);

        
        string password = GeneratePassword(length);

        
        SavePasswordToFile(filename, name, password);

        Console.WriteLine( "\n" + $"Password generated and saved in {filename}.");
    }

    static void EnsureFileExists(string filename)
    {
        if (!File.Exists(filename))
        {
            File.Create(filename).Dispose(); 
        }
    }

    static string GeneratePassword(int length)
    {
        const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:',.<>?/";
        StringBuilder password = new StringBuilder();
        using (var rng = new System.Security.Cryptography.RNGCryptoServiceProvider())
        {
            byte[] buffer = new byte[1];
            while (password.Length < length)
            {
                rng.GetBytes(buffer);
                char character = (char)buffer[0];
                if (characters.IndexOf(character) != -1)
                {
                    password.Append(character);
                }
            }
        }
        return password.ToString();
    }

    static void SavePasswordToFile(string filename, string name, string password)
    {
        using (StreamWriter sw = new StreamWriter(filename, append: true))
        {
            sw.WriteLine($"{name}: {password}");
        }
    }
}



