# Project overview
Battery Monitoring System project is designed to monitor the status of a large number of batteries simultaneously. It consists of three different boards: a Master board, a datalogger board, and a current sensing board.

The Master board is the central hub of the system, responsible for gathering data from the datalogger and current sensing boards. It then sends this data to a PC for monitoring purposes.

The datalogger board is designed to monitor the voltage and temperature of individual battery lines. It contains 20 lines, each capable of gathering data from a single battery, as well as two temperature sensors. When requested by the Master board, the datalogger board sends all of the voltage channel data to the Master board.

The current sensing board is responsible for calculating the current of the entire charging pack. It sends this data to the Master board.

In this project, there is only one Master board and one current sensing board, but there are 30 datalogger boards, making it capable of monitoring a large number of batteries at once.

Overall, the Battery Monitoring System project is designed to provide accurate and reliable monitoring of battery status, ensuring optimal performance and safety. The project can be useful in a variety of applications, such as in electric vehicles, renewable energy systems, and backup power systems.
