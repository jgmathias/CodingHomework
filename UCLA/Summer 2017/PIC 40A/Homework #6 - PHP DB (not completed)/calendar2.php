#!/usr/local/bin/php
<?php print '<?xml version="1.0" encoding="utf-8" ?> '; ?> 
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN"
 "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">
<html xmlns="http://www.w3.org/1999/xhtml"
      xmlns:v="urn:schemas-microsoft-com:vml">
	<head>
		<title>Calendar</title> 
		<link rel="stylesheet" type="text/css" href="calendar.css" />
	</head>
	
	<body>

		<div class="container">
			<?php
				date_default_timezone_set("America/Los_Angeles");
				
				if(!isset($_GET[time_stamp]))
				{
					$now = time();
				}
				else
				{
					$now =$_GET[time_stamp];
				}
				
				$currentdayandtime = date("D, F j, Y, g:i a",$now-0);
				print "<h1>"."James's hourly schedule for ".$currentdayandtime."</h1>";
				$firsthour = mktime(date("H", $now), 0, 0, date("n", $now), date("j", $now), date("Y", $now));
		
				print '<table id="event_table">';
					print '<tr><th class="hr_td"></th><th class="table_header">'.'Work'.'</th><th class="table_header">'.'School'.'</th><th class="table_header">'.'Fun'.'</th></tr>';
					
					for($hour = 0; $hour <=12; $hour++)
					{
						if($hour % 2 == 0)
						{
							$parity = "even";
						}
						else
						{
							$parity = "odd";
						}
					
						$thishour =  mktime(date("H", $firsthour)+$hour, 0, 0, date("n", $firsthour), date("j", $firsthour), date("Y", $firsthour));
						print '<tr class="'.$parity.'_row"><td class="hr_td">'.date("g",$thishour).':00'.date("a",$thishour).'</td><td>'.'a'.'</td><td>'.'b'.'</td><td>'.'c'.'</td></tr>';
					}
			
				print '</table>'
			?>
			
			<div>
				<form id="prev" method="get" action="calendar2.php">
					<p>
						<input type="hidden" name="time_stamp" value='<?php print $now - 12*60*60;?>' />
						<input type="submit" value="Previous twelve hours"/>
					</p>
				</form>

				<form id="next" method="get" action="calendar2.php">
					<p>
						<input type="hidden" name="time_stamp" value='<?php print $now + 12*60*60;?>' />
						<input type="submit" value="Next twelve hours"/>
					</p>
				</form>
				
				<form id="today" method="get" action="calendar2.php">
					<p>
						<input type="submit" value="Today" value='0'/>
					</p>
				</form>
			</div>
		
		</div>
	</body>
</html>
