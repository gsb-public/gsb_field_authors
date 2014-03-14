(function ($) {

/**
 * Responds to visibility toggling.
 */
Drupal.behaviors.gsbFieldAuthors = {
  attach: function (context) {
    $(context).find('.gsb-field-authors-visibility').once(function () {
      var $element = $(this);
      // Create a new Drupal.ajax object that responds to the
      // gsb_field_authors_change event.
      var ajax = new Drupal.ajax(false, $element, {
        event: 'gsb_field_authors_change',
        url: Drupal.settings.basePath + 'gsb-field-authors/visibility-update/' + $element.data('gsb-field-authors-entity-type') + '/' + $element.data('gsb-field-authors-entity-id')
      });

      // When the element is changed, store the new value in the ajax data and
      // trigger the event.
      $element.change(function () {
        ajax.options.data.profile_visibility_value = $(this).val();
        $(ajax.element).trigger('gsb_field_authors_change');
      });
    });
  }
};

/**
 * Process the response from updating the visibility.
 */
Drupal.ajax.prototype.commands.gsb_field_authors_result = function (ajax, response, status) {
};

}(jQuery));
