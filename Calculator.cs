using System;

namespace Calculator
{
    class Program
    {
        public class Calculator
        {
            public int Add(params int[] Numbres)
            {
                var Total = 0;
                if (Numbres.Length == 0)
                {
                    return 0;
                }
                for (int i=0; i < Numbres.Length; i++)
                {
                    Total += Numbres[i];
                }
                return Total;
            }
        }

        static void Main(string[] args)
        {
            var Calc = new Calculator();

            Console.WriteLine(Calc.Add(1, 4, 5, 2));

        } 
    }
}
