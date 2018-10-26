using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Document_Merger
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Document\n");
            Console.Write("Enter the name of the document: ");
            Console.Write("\n");
            string doc1 = Console.ReadLine();
            //check if file exist
                while(File.Exists(doc1) == false)
                {
                Console.Write("File does not exist. Try another file: ");
                doc1 = Console.ReadLine();
                Console.Write("\n");
            }

            //then ask user for a second doc
            Console.Write("Enter the name of the document: ");
            Console.Write("\n");
            string doc2 = Console.ReadLine();

            //check if that file exist
                while (File.Exists(doc2) == false)
                {
                Console.Write("File does not exist. Try another file: ");
                doc2 = Console.ReadLine();
                Console.Write("\n");
            }

            //merge the two names and append .txt to the end of that name
            doc1 = doc1.Replace(".txt", "");
            doc2 = doc1.Replace(".txt", "");

            string combined = doc1 + doc2;
            combined += ".txt";

            //read the txt of both and merge them
            doc1 = File.ReadAllLines("C:\\ {0}.txt", doc1);
            doc2 = File.ReadAllLines("C:\\ {0}.txt", doc2);

            using (StreamWriter writer = File.CreateText(@"*DIRECTORY*\FINALOUTPUT.txt"))
            {
                int lineNum = 0;
                while (lineNum < doc1.Length || lineNum < doc2.Length)
                {
                    if (lineNum < doc1.Length)
                        writer.WriteLine(doc1[lineNum]);
                    if (lineNum < doc2.Length)
                        writer.WriteLine(doc2[lineNum]);
                    lineNum++;
                }
            }




            Console.WriteLine("Do you want to combine more file? ");
            string answer = Console.ReadLine();

            while (answer != null)
            {
                Console.WriteLine("Document\n");
                Console.Write("Enter the name of the document: ");
                Console.Write("\n");
                doc1 = Console.ReadLine();
                //check if file exist
                while (File.Exists(doc1) == false)
                {
                    Console.Write("File does not exist. Try another file: ");
                    doc1 = Console.ReadLine();
                    Console.Write("\n");
                }

                //then ask user for a second doc
                Console.Write("Enter the name of the document: ");
                Console.Write("\n");
                doc2 = Console.ReadLine();

                //check if that file exist
                while (File.Exists(doc2) == false)
                {
                    Console.Write("File does not exist. Try another file: ");
                    doc2 = Console.ReadLine();
                    Console.Write("\n");
                }

                //merge the two names and append .txt to the end of that name
                doc1 = doc1.Replace(".txt", "");
                doc2 = doc1.Replace(".txt", "");

                combined = doc1 + doc2;
                combined += ".txt";

                //read the txt of both and merge them
                doc1 = File.ReadAllLines("C:\\ {0}.txt", doc1);
                doc2 = File.ReadAllLines("C:\\ {0}.txt", doc2);

                using (StreamWriter writer = File.CreateText(@"*DIRECTORY*\FINALOUTPUT.txt"))
                {
                    int lineNum = 0;
                    while (lineNum < doc1.Length || lineNum < doc2.Length)
                    {
                        if (lineNum < doc1.Length)
                            writer.WriteLine(doc1[lineNum]);
                        if (lineNum < doc2.Length)
                            writer.WriteLine(doc2[lineNum]);
                        lineNum++;
                    }
                }
            }

                //make an exception
                if (combined == null)
            {
                Console.WriteLine("Document name and content did not save. Exiting program.");
                return;
            }

            else
            {
                Console.WriteLine("{0} was successfully saved. The document contains {1} characters.", combined,);
                return;
            }
        }
    }
}
