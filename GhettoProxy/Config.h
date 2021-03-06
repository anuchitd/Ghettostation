/*########################################### BOARD PINOUTS #########################################################
 Pins for Arduino Mini
 *SERIAL TELEMETRY INPUT PINOUT:
 
     Use TX/RX pads
     
 *SERIAL LTM OUTPUT PINOUT ( AltSoftSerial):
 
     TX: D9 on arduino mini/nano 

*/
/*############################################## CONFIGURATION ####################################################
 # Comment/uncomment/edit according to your needs.
 ##################################################################################################################*/

//########## OPTIONS ###############################################################################################
//INPUT PROTOCOL
// Choose only one.

//#define PROTOCOL_UAVTALK                      // OpenPilot / Taulabs protocol
//#define PROTOCOL_MSP                          // MSP from Multiwii / Baseflight
//#define PROTOCOL_MAVLINK                      // Mavlink for Ardupilot / Autoquad / PixHawk / Taulabs (UAVOmavlinkBridge)
//#define PROTOCOL_NMEA                         // GPS NMEA ASCII protocol
//#define PROTOCOL_UBLOX                        // GPS UBLOX binary protocol
#define PROTOCOL_NAZATALK                       // DJI NAZA
#define GPS_PROTOCOL_DJI                        // DJI NAZA 

//!uncomment to use altitude from Baro. Use GPS alt if commented.
//#define BARO_ALT

//INPUT BAUDRATE
// #define INPUT_BAUD 57600
// DJI NAZA
#ifdef GPS_PROTOCOL_DJI
#define INPUT_BAUD  115200 // DJI NAZA GPS communication protocol
#else
#define INPUT_BAUD  57600  
#endif
 
 

// GhettoProxy just listen & convert in passive mode. If disabled, it will initiate queries packet.
#define PASSIVEMODE 1

//OUTOPUT BAUDRATE
#define OUTPUT_BAUD 2400


//#define DEBUG
