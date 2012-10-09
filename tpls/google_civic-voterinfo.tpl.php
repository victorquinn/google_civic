<?php

/**
 * @file Google Civic Voterinfo Template.
 */
?>

<h1><?php print $title; ?></h1>
<?php if ($locations) : ?>
  <?php foreach ($locations as $location) : ?>
  <div class="google_civic-polling-location vcard">
    <p class="fn org"><?php print $location->address->locationName; ?></p>
    <div class="adr">
      <p class="street-address"><?php print $location->address->line1; ?> <?php print $location->address->line2; ?> <?php print $location->address->line3; ?></p>
      <div>
        <p class="locality"><?php print $location->address->city; ?></p>, 
        <p class="region"><?php print $location->address->state; ?></p> 
        <p class="postal-code"><?php print $location->address->zip ?></p>
        <p class="country-name"></p>
      </div>
    </div>
  </div>
  <div class="google_civic-polling-hours"><?php print $location->pollingHours; ?></div>
  <?php endforeach; ?>
  <div><?php print $map; ?></div>
  <div>Election Info: <?php print $election_info_link; ?></div>
<?php endif; ?>

