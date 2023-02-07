using System;
using System.Collections.Generic;
using System.Text;

namespace coding_training_4ch
{
    class Doomsday
    {
        static string[] days = { "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" };
        static Dictionary<int, int> dict = new Dictionary<int, int>();
        public static void Algorithm()
        {
            Initialize();
            Console.Write("input year : ");
            int year = int.Parse(Console.ReadLine());
            Console.Write("input month : ");
            int month = int.Parse(Console.ReadLine());
            Console.Write("input day : ");
            int day = int.Parse(Console.ReadLine());

            GetDate(year,month, day, year % 4 == 0);
        }

        public static void Initialize()
        {
            dict.Add(1, 3);
            dict.Add(2, 28);
            dict.Add(3, 0);
            dict.Add(4, 4);
            dict.Add(5, 9);
            dict.Add(6, 6);
            dict.Add(7, 11);
            dict.Add(8, 8);
            dict.Add(9, 5);
            dict.Add(10, 10);
            dict.Add(11, 7);
            dict.Add(12, 12);
        }

        public static int GetDoomsday(int year)
        {
            int century = year / 100;
            int year_ten = year % 100;
            int doomsday;

            switch (century)
            {
                case 18:
                    doomsday = 4; //금
                    break;
                case 19:
                    doomsday = 2; //수
                    break;
                case 20:
                    doomsday = 1; //화
                    break;
                case 21:
                    doomsday = 6; //일
                    break;
                default:
                    doomsday = -1; //해당없음
                    break;
            }

            if (doomsday == -1) return doomsday;
            
            doomsday += year_ten + year_ten / 4;
            doomsday %= 7;
           
            return doomsday; // 0:월,1:화,2:수,3:목,4:금,5:토,6:일
        }
        public static void GetDate(int year,int month, int day,bool isLeapYear)
        {
            int doomsdate = GetDoomsday(year);
            int doomsday = dict[month];
            if ((month == 2 || month == 1) & isLeapYear) doomsday++;
            int diff = doomsday-day;

            if(diff < 0)
            {
                diff = Math.Abs(diff);
                doomsdate += diff;
                doomsdate %= 7;
            }
            else if(diff > 0)
            {
                doomsdate -= diff;
                while (doomsdate < 0) doomsdate += 7;
            }

            Console.WriteLine($"{year}/{month}/{day} date : {days[doomsdate]}");
        }
    }
}
