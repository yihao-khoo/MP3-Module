/*****************************************************************************

	Author  	Continental Electronic Enterprise
	Version 	V1.0

	Copyright www.continentalee.com.sg
	All right reserved.

	All text above must be included in any redistribution

*****************************************************************************/

#include "MP3_Module.h"

SoftwareSerial COM_SOFT(2, 3);

void MP3::begin()
{
	COM_SOFT.begin(9600);
}

void MP3::send_cmd(uint8_t *cmd)
{
    uint8_t i;
    uint8_t length;
    length = cmd[1] + 2;
	if (length > CMD_BUF_LEN){
		return;
	}

    cmd[0] = 0x7E;
    cmd[length-1] = 0xEF;
	for (i = 0; i < length; i++){
		COM_SOFT.write(cmd[i]);
	}
}

void MP3::select_file(uint16_t file)
{
	cmd_buf[1] = 0x04;
	cmd_buf[2] = 0x41;
	cmd_buf[3] = (uint8_t)(file >> 8);
	cmd_buf[4] = (uint8_t)file;
	send_cmd(cmd_buf);
}

void MP3::play()
{
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x01;
	send_cmd(cmd_buf);
}

void MP3::pause()
{
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x02;
	send_cmd(cmd_buf);
}

void MP3::next()
{
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x03;
	send_cmd(cmd_buf);
}

void MP3::previous()
{
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x04;
	send_cmd(cmd_buf);
}

void MP3::stop()
{
    cmd_buf[1]=0x02;
    cmd_buf[2]=0x0E;
    send_cmd(cmd_buf);
}

void MP3::volume_up()
{
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x05;
	send_cmd(cmd_buf);
}

void MP3::volume_down()
{
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x06;
	send_cmd(cmd_buf);
}

void MP3::volume(uint8_t vol)
{
	cmd_buf[1] = 0x03;
	cmd_buf[2] = 0x31;
	cmd_buf[3] = vol & 0x01F;
	send_cmd(cmd_buf);
}

void MP3::eq(uint8_t eq)
{
	cmd_buf[1] = 0x03;
	cmd_buf[2] = 0x32;
	cmd_buf[3] = eq;
	send_cmd(cmd_buf);
}

void MP3::set_mode(uint8_t mode)
{
	cmd_buf[1] = 0x03;
	cmd_buf[2] = 0x33;
	cmd_buf[3] = mode;
	send_cmd(cmd_buf);
}

int MP3::get_status()
{
	while(COM_SOFT.available()) COM_SOFT.read();
	
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x10;
	send_cmd(cmd_buf);
	
	delay(100);
	if (COM_SOFT.available()){
		data = "";
		while(COM_SOFT.available()){
			char c = COM_SOFT.read();
			data += c;
		}
	}
	
	return data.toInt();
}

int MP3::get_volume()
{
	while(COM_SOFT.available()) COM_SOFT.read();
	
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x11;
	send_cmd(cmd_buf);
	
	delay(100);
	if (COM_SOFT.available()){
		data = "";
		while(COM_SOFT.available()){
			char c = COM_SOFT.read();
			data += c;
		}
	}
	
	return data.toInt();
}

int MP3::get_eq()
{
	while(COM_SOFT.available()) COM_SOFT.read();
	
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x12;
	send_cmd(cmd_buf);
	
	delay(100);
	if (COM_SOFT.available()){
		data = "";
		while(COM_SOFT.available()){
			char c = COM_SOFT.read();
			data += c;
		}
	}
	
	return data.toInt();
}

int MP3::get_mode()
{
	while(COM_SOFT.available()) COM_SOFT.read();
	
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x13;
	send_cmd(cmd_buf);
	
	delay(100);
	if (COM_SOFT.available()){
		data = "";
		while(COM_SOFT.available()){
			char c = COM_SOFT.read();
			data += c;
		}
	}
	
	return data.toInt();
}

int MP3::get_current_track_time()
{
	while(COM_SOFT.available()) COM_SOFT.read();
	
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x1C;
	send_cmd(cmd_buf);
	
	delay(100);
	if (COM_SOFT.available()){
		data = "";
		while(COM_SOFT.available()){
			char c = COM_SOFT.read();
			data += c;
		}
	}
	
	return data.toInt();
}

int MP3::get_track_time()
{
	while(COM_SOFT.available()) COM_SOFT.read();
	
	cmd_buf[1] = 0x02;
	cmd_buf[2] = 0x1D;
	send_cmd(cmd_buf);
	
	delay(100);
	if (COM_SOFT.available()){
		data = "";
		while(COM_SOFT.available()){
			char c = COM_SOFT.read();
			data += c;
		}
	}
	
	return data.toInt();
}