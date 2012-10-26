<?php

/**
 * @file Google Civic Voterinfo Template.
 */
?>


<div id="google-civic-voterinfo-heading">
  <?= $headline; ?>
</div>
<div id="google-civic-voterinfo">
  <?php if (!empty($locations)) : ?>
    <div id="google-civic-voterinfo-polling-locations">
      <?= $locations; ?>
    </div>
  <?php else: ?>
    <p><?= $sorry ?></p>
    <div id="google-civic-address-form-div">
      <span class="google-civic-search-again">Please ensure your address is in the proper format and try again.</span>
      <?= drupal_render($address_form); ?>
    </div>
  <?php endif; ?>

  <?php if ($map) : ?>
    <div id="google-civic-voterinfo-gmap"><?php print $map; ?></div>
  <?php endif; ?>

  <?php if ($early_locations) : ?>
    <div id="google-civic-voterinfo-early-locations" class="clearfix">
      <div id="google-civic-voterinfo-early-locations-title">
        <?php print t('Early Voting Sites'); ?>
      </div>
      <?php print $early_locations; ?>
    </div>
  <?php endif; ?>

  <?php if ($election_info_link) : ?>
    <div id="google-civic-voterinfo-election-info">
      <?php print
        t('For more information, visit: !link',
            array('!link' => $election_info_link));
      ?>
    </div>
  <?php endif; ?>

</div>
