/* 
 OpenMQTTGateway - ESP8266 or Arduino program for home automation 

 Act as a wifi or ethernet gateway between your 433mhz/infrared IR signal and a MQTT broker 
 Send and receiving command by MQTT
 
 This files enables to set your parameter for the DHT11/22 sensor
 
 Copyright: (c)Florian ROBERT
 
 This file is part of OpenMQTTGateway.
 
 OpenMQTTGateway is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 OpenMQTTGateway is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef config_WebContent_h
#define config_WebContent_h

/*------------------- ----------------------*/

// TODO: Create a script to generate these from WebPack

#define button_upgrade "<p><form id=but5 style='display: block;' action='up' method='get'><button>Firmware Upgrade</button></form></p>"

// Configuration Menu

#define configure_1 "<p><form action='wi' method='get'><button>Configure WiFi</button></form></p>"
#define configure_2 "<p><form action='mq' method='get'><button>Configure MQTT</button></form></p>"
#  if defined(ZgatewayCloud)
#define configure_3 "<p><form action='cl' method='get'><button>Configure Cloud</button></form></p>"
#else 
#define configure_3 
#endif
#define configure_4
#define configure_5
#define configure_6
#define configure_7
#define configure_8

const char header_html[] = "<!DOCTYPE html><html lang=\"en\" class= \" \"><head><meta charset='utf-8'><meta name= \"viewport \" content= \"width=device-width,initial-scale=1,user-scalable=no \"/><title>%s</title><script> var x = null, lt, to, tp, pc = ''; function eb(s) { return document.getElementById(s); } function qs(s) { return document.querySelector(s); } function sp(i) { eb(i).type = (eb(i).type === 'text' ? 'password' : 'text'); } function wl(f) { window.addEventListener('load', f); }";

const char root_script[] = "var ft; function la(p) {a = p || '';clearTimeout(ft);clearTimeout(lt);if (x != null) { x.abort()}x = new XMLHttpRequest();x.onreadystatechange = function() { if (x.readyState == 4 && x.status == 200) {var s = x.responseText.replace(/{t}/g,\"<table style='width:100%'> \").replace(/{s}/g,\"<tr><th> \").replace(/{m}/g,\"</th><td style='width:20px;white-space:nowrap'> \").replace(/{e}/g,\"</td></tr> \");eb('l1').innerHTML = s;clearTimeout(ft);clearTimeout(lt);lt = setTimeout(la, 2345); }};x.open('GET', '.?m=1' + a, true);x.send();ft = setTimeout(la, 20000); } function lc(v, i, p) {if (eb('s')) { if (v == 'h' || v == 'd') {var sl = eb('sl4').value;eb('s').style.background = 'linear-gradient(to right,rgb(' + sl + '%,' + sl + '%,' + sl + '%),hsl(' + eb('sl2').value + ',100%%,50%%))'; }}la('&' + v + i + '=' + p); } wl(la);";

const char restart_script[] = "setTimeout(function() { location.href = '.'; }, 15000);";

const char information_script[] = "function i() { var s, o = \"<table style='width:100%%'><tr><th>%s</td></tr></table>\"; s = o.replace(/}1/g, \"</td></tr><tr><th>\").replace(/}2/g, \"</th><td>\"); eb('i').innerHTML = s; } wl(i);";

const char console_script[] = " var sn = 0, id = 0, ft, ltm = 2345; function l(p) { var c, o = ''; clearTimeout(lt); clearTimeout(ft); t = eb('t1'); if (p == 1) { c = eb('c1'); o = '&c1=' + encodeURIComponent(c.value); c.value = ''; t.scrollTop = 99999; sn = t.scrollTop; } if (t.scrollTop >= sn) { if (x != null) { x.abort(); } x = new XMLHttpRequest(); x.onreadystatechange = function() { if (x.readyState == 4 && x.status == 200) { var z, d; d = x.responseText.split(/}1/); id = d.shift(); if (d.shift() == 0) { t.value = ''; } z = d.shift(); if (z.length > 0) { t.value += z; } t.scrollTop = 99999; sn = t.scrollTop; clearTimeout(ft); lt = setTimeout(l, ltm); } }; x.open('GET', 'cs?c2=' + id + o, true); x.send(); ft = setTimeout(l, 20000); } else { lt = setTimeout(l, ltm); } return false; } wl(l); var hc = [], cn = 0; function h() { eb('c1').addEventListener('keydown', function(e) { var b = eb('c1'), c = e.keyCode; if (38 == c || 40 == c) { b.autocomplete = 'off'; } 38 == c ? (++cn > hc.length && (cn = hc.length), b.value = hc[cn - 1] || '') : 40 == c ? (0 > --cn && (cn = 0), b.value = hc[cn - 1] || '') : 13 == c && (hc.length > 19 && hc.pop(), hc.unshift(b.value), cn = 0) }); } wl(h);";

const char script[] = "function jd() { var t = 0, i = document.querySelectorAll('input,button,textarea,select'); while (i.length >= t) { if (i[t]) { i[t]['name'] = (i[t].hasAttribute('id') && (!i[t].hasAttribute('name'))) ? i[t]['id'] : i[t]['name']; } t++; } } wl(jd); </script>";

const char style[] = "<style> div, fieldset, input, select { padding: 5px; font-size: 1em; } fieldset { background: #DDDDDD; } p { margin: 0.5em 0; } input { width: 100%; box-sizing: border-box; -webkit-box-sizing: border-box; -moz-box-sizing: border-box; background: #EEEEEE; color: #2F2F2F; } input[type=checkbox], input[type=radio] { width: 1em; margin-right: 6px; vertical-align: -1px; } input[type=range] { width: 99%; } select { width: 100%; background: #EEEEEE; color: #2F2F2F; } textarea { resize: vertical; width: 98%; height: 318px; padding: 5px; overflow: auto; background: #2F2F2F; color: #7BB461; } body { text-align: center; font-family: verdana, sans-serif; background: #EEEEEE; color:#2E2F2F;} td { padding: 0px; } button { border: 0; border-radius: 0.3rem; background: #4B98D1; color: #faffff; line-height: 2.4rem; font-size: 1.2rem; width: 100%; -webkit-transition-duration: 0.4s; transition-duration: 0.4s; cursor: pointer; } button:hover { background: #025880;font-weight: bold; } .bred { background: #FFA900; } .bred:hover { background: #FF8000; font-weight: bold;} .bgrn { background: #7BB461; } .bgrn:hover { background: #3A772A;font-weight: bold; } a { color: #4B98D1; text-decoration: none; } .p { float: left; text-align: left; } .q { float: right; text-align: right; } .r { border-radius: 0.3em; padding: 2px; margin: 6px 2px; } </style></head>";

const char root_body[] = "<body><div style='text-align:left;display:inline-block;min-width:340px;'><div style='text-align:center;'><noscript> To use, please enable JavaScript <br></noscript><h3>%s</h3><h2>%s</h2></div><fieldset><div style='padding:0;' id='l1' name='l1'></div></fieldset><div id=but3d style='display: block;'></div><p><form id=but3 style='display: block;' action='cn' method='get'><button>Configuration</button></form></p><p><form id=but4 style='display: block;' action='in' method='get'><button>Information</button></form></p>" button_upgrade "<p><form id=but14 style='display: block;' action='cs' method='get'><button>Console</button></form></p><p><form id=but0 style='display: block;' action='.' method='get' onsubmit='return confirm(\"Confirm Restart\");'><button name='rst' class='button bred'>Restart</button></form></p>";

const char config_body[] = "<body><div style='text-align:left;display:inline-block;min-width:340px;'><div style='text-align:center;'><noscript> To use please enable JavaScript <br></noscript><h3>%s</h3><h2>%s</h2></div>" configure_1 "" configure_2 "" configure_3 "" configure_4 "" configure_5 "" configure_6 "" configure_7 "" configure_8 "<div id=but1d style='display: block;'></div><p><form id=but1 style='display: block;' action='rt' method='get' onsubmit='return confirm(\"Confirm Reset Configuration\");'><button name='non' class='button bred'>Reset Configuration</button></form></p><div id=but2d style='display: block;'></div><p><form id=but2 style='display: block;' action='.' method='get'><button>Main Menu</button></form></p>";

const char reset_body[] = "<body><div style='text-align:left;display:inline-block;min-width:340px;'><div style='text-align:center;'><noscript>To use please enable JavaScript<br></noscript><h3>%s</h3><h2>%s</h2></div><div style='text-align:center;'>%s</div><br><div style='text-align:center;'>Device will restart in a few seconds</div><br><div id=but2d style=\"display: block;\"></div><p><form id=but2 style=\"display: block;\" action='.' method='get'><button>Main Menu</button></form></p>";

const char cloud_body[] = "<body><div style='text-align:left;display:inline-block;min-width:340px;'><div style='text-align:center;'><noscript>To use Tasmota, please enable JavaScript<br></noscript><h3>%s</h3><h2>%s</h2></div><fieldset><legend><b>&nbsp;Cloud Configuration&nbsp;</b></legend><form method='get' action='cl'><p><label><input id='cl-en' type='checkbox' %s><b>Enable Cloud Connection</b></label></p><br><p><label><input id='cl-lk' type='checkbox' disabled><b>Cloud Account%s Linked</b></label></p><br><button name='save' type='submit' class='button bgrn'>Save</button></form></fieldset><p><form action='%s' method='get'><input type='hidden' name='macAddress' value='%s'/><input type='hidden' name='redirect_uri' value='%s'/><input type='hidden' name='gateway_name' value='%s'/><input type='hidden' name='uptime' value='%d'/><input type='hidden' name='RT' value='%d'/><button>Link Cloud Account</button></form></p><div id=but3d style=\"display: block;\"></div><p><form id=but3 style=\"display: block;\" action='cn' method='get'><button>Configuration</button></form></p>";

const char token_body[] = "<body><div style='text-align:left;display:inline-block;min-width:340px;'><div style='text-align:center;'><noscript>To use please enable JavaScript<br></noscript><h3>%s</h3><h2>%s</h2></div><div style='text-align:center;'>Link Cloud Account</div><br><div style='text-align:center;'>Cloud was successfully linked</div><br><div id=but2d style=\"display: block;\"></div><p><form id=but2 style=\"display: block;\" action='cn' method='get'><button>Configuration</button></form></p>";

const char console_body[] = "<body><div style='text-align:left;display:inline-block;min-width:340px;'><div style='text-align:center;'><noscript> To use please enable JavaScript <br></noscript><h3>%s</h3><h2>%s</h2></div><br><textarea readonly id='t1' cols='340' wrap='off'></textarea><br><br><form method='get' onsubmit='return l(1);'><input id='c1' placeholder='Enter topic and command' autofocus><br></form><div id=but2d style=\"display: block;\"></div><p><form id=but2 style=\"display: block;\" action='.' method='get'><button>Main Menu</button></form></p>";

const char information_body[] = "<body><div style='text-align:left;display:inline-block;min-width:340px;'><div style='text-align:center;'><noscript>To use please enable JavaScript<br></noscript><h3>%s</h3><h2>%s</h2></div><style>td {padding: 0px 5px;}</style><div id='i' name='i'></div><div id=but2d style=\"display: block;\"></div><p><form id=but2 style=\"display: block;\" action='.' method='get'><button>Main Menu</button></form></p>";

const char footer[] = "<div style='text-align:right;font-size:11px;'><hr/><a href='https://community.openmqttgateway.com' target='_blank' style='color:#aaa;'>%s</a></div></div></body></html>";

#endif