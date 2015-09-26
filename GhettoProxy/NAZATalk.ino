/**
 ******************************************************************************
 *
 * @file       NAZATalk.ino
 * @author     Joerg-D. Rothfuchs
 * @brief      Implements a subset of NAZA communication.
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, see <http://www.gnu.org/licenses/> or write to the 
 * Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */


#ifdef PROTOCOL_NAZATALK

#include "NAZATalk.h"


#ifdef GPS_PROTOCOL_DJI
// see http://www.rcgroups.com/forums/showthread.php?t=1995704
#include "GPS_DJI.h"
#endif



//----------------------------------------------------------------------------------
//
//  stage 1	easy soldering		solder the GPS puck cable and configure 1 cable to NAZA for +5V and GND
//	GPS lat/lon				ok
//	distance to home			ok
//	altitude				ok
//	groundspeed				ok
//	course					ok
//	direction to home			ok
//	sat count				ok
//	sat fix					ok
//	climb rate				ok
//	radar					ok
//	time display				ok
//
//
//
//  stage 2a	advanced soldering	solder 1 cable at Atmel 328P pin and 3 resistors at NAZA LED cable adapter
//	active LED symbol			ok	3 resistors + 1 ADC
//
//  stage 2b	advanced soldering	solder 2 cables at Atmel 328P pin and up to 4 resistors and use voltage/current sensor
//	battery voltage				ok	2 resistors + 1 ADC
//	battery current				ok	2 resistors + 1 ADC
//
//  stage 2c	advanced soldering	solder 1 cable at Atmel 328P pin and 2 resistors
//	analog RSSI				ok	2 resistors + 1 ADC
//
//  stage 2d	easy soldering		solder 1 cable at MinimOSD PAL pad (but only for interest for users of Simprop GigaScan RC-RX)
//	packet RSSI				ok	1 INT
//
//
//
//  stage 3a	advanced soldering	solder 2 cables at Atmel 328P pin and configure 1 double PWM cable to NAZA
//	horizon + pitch/roll			TOTEST	2 PCINT
//
//  stage 3b	advanced soldering	solder 2 cables at Atmel 328P pin and configure 2 PWM cables to RC-RX
//	throttle				TOTEST	1 PCINT
//	screen switching			TOTEST	1 PCINT
//
//----------------------------------------------------------------------------------
int nazatalk_read(void) {
  static uint8_t crlf_count = 0;
  int ret = 0;


  // grabbing data
  while (Serial.available() > 0) {
    uint8_t c = Serial.read();


#ifdef GPS_PROTOCOL_DJI
    if (parse_dji(c) == PARSER_COMPLETE_SET) {
      uav_fix_type		= get_dji_status();
      uav_satellites_visible	= get_dji_satellites();
      uav_lat			= get_dji_latitude();
      uav_lon			= get_dji_longitude();
      uav_alt			= get_dji_altitude();  // cm
      uav_heading 		= get_dji_heading();
      uav_groundspeed 	        = get_dji_groundspeed();
//      uav_climb		= -1.0 * get_dji_down();
    }
#endif

  }
}


int nazatalk_state(void)
{
  return 1;
}


#endif // PROTOCOL_NAZATALK
