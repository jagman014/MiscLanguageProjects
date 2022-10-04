using System;

namespace DateAndTime {
    public class Program {
        public static void Main(string[] args) {
            // DateTime
            // read only class that gives access to date and time
            DateTime MyDate = DateTime.Now;

            DateTime MySecondDate = new DateTime(1998, 6, 22);

            // .ToString()
            Console.WriteLine(MyDate.ToString());

            // .ToShortDateString()
            Console.WriteLine(MyDate.ToShortDateString());

            // .ToShortTimeString
            Console.WriteLine(MyDate.ToShortTimeString());

            // .ToLongDateString
            Console.WriteLine(MyDate.ToLongDateString());

            // .ToLongTimeString
            Console.WriteLine(MyDate.ToLongTimeString());

            // arithmetics - add / subtract
            Console.WriteLine(MyDate.AddYears(5).ToShortDateString());

            Console.WriteLine(MyDate.AddHours(-12).ToLongTimeString());

            // access, .Month, .Day, .Hours, etc...
            Console.WriteLine(MyDate.Month.ToString());

            // converts strings to DateTime
            DateTime TestDate = DateTime.Parse("1998-06-22");
            Console.WriteLine(TestDate.ToString());

            // TimeSpan
            // time between two DateTimes (using Subtract)
            TimeSpan DaysPassed = DateTime.Now.Subtract(TestDate);
            Console.WriteLine(DaysPassed.TotalDays);
        }
    }
}
