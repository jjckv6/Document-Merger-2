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
            Console.WriteLine("{0}", args[0]);
            Console.Write("\n");
            string doc1 = args[0];

            Console.Write("Second Doc");
            Console.WriteLine("{0}", args[1]);
            Console.Write("\n");
            string doc2 = args[1];

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
                Console.Write(args.Length);
            }

            Console.WriteLine("Do you want to combine more file? ");
            string answer = Console.ReadLine();

            while (answer != null)
            {
                Console.WriteLine("Document\n");
                Console.WriteLine("{0}", args[0]);
                Console.Write("\n");
                doc1 = args[0];

                Console.Write("Second Doc");
                Console.WriteLine("{0}", args[1]);
                Console.Write("\n");
                doc2 = args[1];

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
                    Console.Write(args.Length);
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
