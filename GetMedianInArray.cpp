using System;
using System.Diagnostics;
using System.Text;

namespace based
{
    class Program
    {

        static void Main(string[] args)
        {
            Console.Clear();
            Console.WriteLine("Welcome");
            float[] array = { 1, 2, 6, 3, 7,3, 8 , 69 };
            float Median;
            Array.Sort(array);
            if ((float)Math.Floor(Convert.ToDecimal(array.Length / 2)) == (float)array.Length / 2)
            {
                Median = ((array[Math.Abs(array.Length / 2)] + array[Math.Abs(array.Length / 2) + 1])/2);
            }
            else
            {
                Median = (array[array.Length / 2]);
            }

            Console.WriteLine(Median);

        }
    }
}
