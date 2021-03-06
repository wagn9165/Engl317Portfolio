<?php include('server.php')?>

<!------------- HTML ------------->
<!DOCTYPE html>
<head>
  <title>Doctor Portal Prescriptions</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <link rel="stylesheet" href="https://www.w3schools.com/lib/w3-theme-blue.css">
  <link href="css/doctorPortal.css" rel='stylesheet'>
  <link rel="stylesheet" href="https://www.w3schools.com/w3css/4/w3.css">
</head>

<body>
  <!--Navbar-->
  <div class="w3-bar w3-theme w3-large">
    <a href="DoctorPortalIndex.php" class="w3-bar-item w3-button w3-hide-small w3-hover-white">BACK</a>
    <div class="nav-right">
      <a href="DoctorPortalIndex.php?logout='1'" class="w3-bar-item w3-button w3-hide-small w3-hover-white">LOGOUT</a>
    </div>
  </div>

  <!--Header-->
  <div class="header w3-theme-d4">
    <h1><b>Prescriptions</b></h1>
  </div>

  <!--Form Errors-->
  <div class="error center">
	<b><?php include('errors.php'); ?></b>
  </div>

  <!--Add Prescriptions Form-->
  <form id="prescriptionForm" class="center" method="post" action="<?php echo htmlspecialchars($_SERVER['PHP_SELF']);?>">
      <h2>Add Prescription</h2>

	  <!--PID Input-->
	  <div class="input-group">
	  	<label><b>PID</b></label>
		<input type="number" class="form-control" name="pid" min="0" required autofocus>
	  </div>

	  <!--Date Input-->
	  <div class="input-group">
	    <label><b>Date</b></label>
		<input type="datetime-local" class="form-control" name="date">
	  </div>

	  <!--Prescription Input-->
	  <div class="input-group">
	    <label><b>Prescription</b></label>
		<select name = "prescription">
		  <option>Select</option>;
		  <?php 
			$query = "SELECT * FROM MedicalProducts;";
			$result = mysqli_query($db2, $query);		
			
			while($row = mysqli_fetch_assoc($result))
			{
			$prod_name = $row['Name'];
				echo "<option value='$prod_name'>$prod_name</option>";
			}
		  ?>
		</select>
	  </div>

	  <!--Submit Button-->
	  <div class="input-group">
		<button type="submit" class="w3-button w3-round w3-blue w3-ripple" name="select_prescription">Submit New Prescription</button>
	  </div>

  </form>
</body>
</html>