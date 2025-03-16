Supla® alternative firmware for Sonoff BASIC R4 with magic switch support.

Configuration options:
1. Activating Magic Switch
2. Filter value - if our switch is not working -> increase the value,
                  if You have random switching -> decrease value
4. In case You can't find the right value according to the point above,
   set the minimum value when the switch is working and turn on the limit
   with the value of about 2000 higher
6. You can turn on debug channel which creates a new channel in Your app
   and shows time in µs of switching so You will know the values for random
   switching and make correction to filter and limit values




SuplaDevice:
  25.01.03 (2024-11-26) 
  espboards: 
  esp32:3.1.1Á


  
Copyright (C) AC SOFTWARE SP. Z O.O.

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
