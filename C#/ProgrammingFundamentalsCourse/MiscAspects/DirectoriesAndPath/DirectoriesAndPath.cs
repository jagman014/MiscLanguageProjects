using System;
using System.IO;

namespace DirectoriesAndPath {
    public class Program {
        public static void Main(string[] args) {
            // directories
            // creating and deleting folders
            string DirPath = Directory.GetCurrentDirectory().ToString() + "\\NewDir";

            if (Directory.Exists(DirPath)) {
                // two ways to delete
                // if dir is empty
                // Directory.Delete(path + "\\NewDir");

                // if dir not empty, recursive delete
                Directory.Delete(DirPath, true);
            }

            // needs dir to not exist
            Directory.CreateDirectory(DirPath);

            // Path class
            // allow us to make changes to string path for dir or files
            string NewPath = DirPath + "\\our_text.txt";

            File.WriteAllText(NewPath, "Wow some words\n");

            // gets directory name
            string DirName = Path.GetDirectoryName(NewPath);
            Console.WriteLine($"Directory Name: {DirName}");

            // gets file extension
            string FileExt = Path.GetExtension(NewPath);
            Console.WriteLine($"File Extension: {FileExt}");

            // get file name
            string FileName = Path.GetFileName(NewPath);
            Console.WriteLine($"File Name: {FileName}");

            // get file name without extension
            string FileNameWOExt = Path.GetFileNameWithoutExtension(NewPath);
            Console.WriteLine($"File Name Without Extension: {FileNameWOExt}");

            // get files root dir
            string Root = Path.GetPathRoot(NewPath);
            Console.WriteLine($"Root Path: {Root}");

            // change file ext of the Path, not the actual file
            string NewFileResult = Path.ChangeExtension(NewPath, ".new");
            Console.WriteLine($"New File: {NewFileResult}");
        }
    }
}
