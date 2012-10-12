<?php

/**
 * @file Google Civic Voterinfo Template.
 */
?>

<div id="google-civic-voterinfo-heading">
  <?php print $headline; ?>
</div>
<div id="google-civic-voterinfo">
<?php if ($locations) : ?>
  <?php print $locations; ?>
<?php else: ?>
  <p>Sorry.  We are unable to find a polling location for your address.</p>
<?php endif; ?>

<?php if ($early_locations) : ?>
  <?php print $early_locations; ?>
<?php endif; ?>

<?php if ($map) : ?>
  <div id="google-civic-voterinfo-gmap"><?php print $map; ?></div>
<?php endif; ?>

<?php if ($election_info_link) : ?>
  <div id="google-civic-voterinfo-election-info">For more information, visit:
    <?php print $election_info_link; ?>
  </div>
<?php endif; ?>

</div>
<div id="google-civic-address-form-div">
  <p>Find voter information for another address:</p>
  <?php print $address_form; ?>
</div>

