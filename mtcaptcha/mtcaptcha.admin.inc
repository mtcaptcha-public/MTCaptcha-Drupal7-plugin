<?php

/**
 * @file
 * Provides the MTCaptcha administration settings.
 */

function mtcaptcha_admin_settings() {
  $form['mtcaptcha_general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => check_plain('General settings'),
  );

  $form['mtcaptcha_general_settings']['mtcaptcha_site_key'] = array(
    '#type' => 'textfield',
    '#title' => check_plain('Site key'),
    '#default_value' => variable_get('mtcaptcha_site_key', ''),
    '#maxlength' => 40,
    '#description' => t('The site key given to you when you <a href="@url">register for mtcaptcha</a>.', array('@url' => 'https://admin.mtcaptcha.com/signup/profile?plantype=A')),
    '#required' => TRUE,
  );
  $form['mtcaptcha_general_settings']['mtcaptcha_private_key'] = array(
    '#type' => 'textfield',
    '#title' => check_plain('Private key'),
    '#default_value' => variable_get('mtcaptcha_private_key', ''),
    '#maxlength' => 128,
    '#description' => t('The private key given to you when you <a href="@url">register for mtcaptcha</a>.', array('@url' => 'https://admin.mtcaptcha.com/signup/profile?plantype=A')),
    '#required' => TRUE,
  );

  $form['mtcaptcha_widget_settings'] = array(
    '#type' => 'fieldset',
    '#title' => check_plain('Widget settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['mtcaptcha_widget_settings']['mtcaptcha_theme'] = array(
    '#type' => 'select',
    '#title' => check_plain('Theme'),
    '#description' => check_plain('Defines which theme to use for mtcaptcha.'),
    '#options' => array(
      'standard' => check_plain('standard'),
      'overcast' => check_plain('overcast'),
      'neowhite' => check_plain('neowhite'),
      'goldbezel' => check_plain('goldbezel'),
      'blackmoon' => check_plain('blackmoon'),
      'darkruby' => check_plain('darkruby'),
      'touchoforange' => check_plain('touchoforange'),
      'caribbean' => check_plain('caribbean'),
      'woodyallen' => check_plain('woodyallen'),
      'chrome' => check_plain('chrome'),
      'highcontrast' => check_plain('highcontrast'),
    ),
    '#default_value' => variable_get('mtcaptcha_theme', 'standard'),
  );
  $form['mtcaptcha_widget_settings']['mtcaptcha_language'] = array(
    '#type' => 'select',
    '#title' => check_plain('Language'),
    '#description' => check_plain('Language the labels need to be displayed.'),
    '#options' => array(
      'en' => check_plain('English(en)'),
      'ar' => check_plain('Arabic(ar)'),
      "af" => check_plain("Afrikaans(af)"),
      "am" => check_plain("Amharic(am)"),
      "hy" => check_plain("Armenian(hy)"),
      "az" => check_plain("Azerbaijani(az)"),
      "eu" => check_plain("Basque(eu)"),
      "bn" => check_plain("Bengali(bn)"),
      "bg" => check_plain("Bulgarian(bg)"),
      "ca" => check_plain("Catalan(ca)"),
      "zh-hk" => check_plain("Chinese (Hong Kong)(zh-HK)"),
      "zh" => check_plain("Chinese(zh)"),
      "hr" => check_plain("Croatian(hr)"),
      "cs" => check_plain("Czech(cs)"),
      "da" => check_plain("Danish(da)"),
      "nl" => check_plain("Dutch(nl)"),
      "en" => check_plain("English"),
      "et" => check_plain("Estonian(et)"),
      "fil" => check_plain("Filipino(fil)"),
      "fi" => check_plain("Finnish(fi)"),
      "fr" => check_plain("French(fr)"),
      "gl" => check_plain("Galician(gl)"),
      "ka" => check_plain("Georgian(ka)"),
      "de" => check_plain("German(de)"),
      "el" => check_plain("Greek(el)"),
      "gu" => check_plain("Gujarati(gu)"),
      "iw" => check_plain("Hebrew(iw)"),
      "hi" => check_plain("Hindi(hi)"),
      "hu" => check_plain("Hungarain(hu)"),
      "is" => check_plain("Icelandic(is)"),
      "id" => check_plain("Indonesian(id)"),
      "it" => check_plain("Italian(it)"),
      "ja" => check_plain("Japanese(ja)"),
      "kn" => check_plain("Kannada(kn)"),
      "ko" => check_plain("Korean(ko)"),
      "ko" => check_plain("Korean(ko)"),
      "lv" => check_plain("Latvian(lv)"),
      "lt" => check_plain("Lithuanian(lt)"),
      "ms" => check_plain("Malay(ms)"),
      "ml" => check_plain("Malayalam(ml)"),
      "mr" => check_plain("Marathi(mr)"),
      "mn" => check_plain("Mongolian(mn)"),
      "no" => check_plain("Norwegian(no)"),
      "fa" => check_plain("Persian(fa)"),
      "pl" => check_plain("Polish(pl)"),
      "pt" => check_plain("Portuguese(pt)"),
      "ro" => check_plain("Romanian(ro)"),
      "ru" => check_plain("Russian(ru)"),
      "si" => check_plain("Sinhalese(si)"),
      "sr" => check_plain("Serbian(sr)"),
      "sk" => check_plain("Slovak(sk)"),
      "sl" => check_plain("Slovenian(sl)"),
      "es" => check_plain("Spanish(es)"),
      "sw" => check_plain("Swahili(sw)"),
      "sv" => check_plain("Swedish(sv)"),
      "ta" => check_plain("Tamil(ta)"),
      "te" => check_plain("Telugu(te)"),
      "th" => check_plain("Thai(th)"),
      "tr" => check_plain("Turkish(tr)"),
      "uk" => check_plain("Ukrainian(uk)"),
      "ur" => check_plain("Urdu(ur)"),
      "vi" => check_plain("Vietnamese(vi)"),
      "zu" => check_plain("Zulu(zu)")
    ),
    '#default_value' => variable_get('mtcaptcha_language', 'en'),
  );
  $form['mtcaptcha_widget_settings']['mtcaptcha_widgetsize'] = array(
    '#title' => check_plain('Captcha Widget size'),
    '#type' => 'select',
    '#options' => array(
      'standard' => check_plain('Standard'),
      'mini' => check_plain('Modern Mini'),
    ),
    '#default_value' => variable_get('mtcaptcha_widgetsize'),
    '#description' => check_plain('Defines which widgetsize to use for mtcaptcha.'),
  );
  $form['mtcaptcha_widget_settings']['mtcaptcha_enablecaptcha'] = array(
    "#type" => "select",
    "#title" => check_plain("Enable MTCaptcha for"),
    "#options" => array(
      "all" => check_plain("All Users"),
      "login" => check_plain("Logged In Users"),
      "logout" => check_plain("Logged Out Users"),      
    ),    
    "#default_value" => variable_get('mtcaptcha_enablecaptcha', "all"),
    "#description" => t('<br> The MTCaptcha will be embedded in Login Form <br> and 
    Reset Password Form even though the Enable MTCaptcha is selected for logged <br> in users. If needed we can disable 
    MTCaptcha for these forms by choosing below options')
  );

  $form_ids = array(
    'user_login' => check_plain('Login Form'),
    'user_register_form' => check_plain('Registration Form'), 
    'user_pass' => check_plain('Reset Password Form'),
    'user_profile_form' => check_plain('Change Password Form'),
    'comment_node_article_form' => check_plain('Comment Form'),
    'contact_site_form' => check_plain('Contact Form')
  );

  $form['mtcaptcha_widget_settings']['mtcaptcha_enable'] = array(
    '#title' => check_plain('MTCaptcha is applied for'),
    '#type' => 'checkboxes',
    '#default_value' => variable_get('mtcaptcha_enable', array_keys($form_ids)),
    '#description' => check_plain('Please enable MTCaptcha for above forms'),
    '#options' => $form_ids,
  );

  $form['mtcaptcha_widget_settings']['mtcaptcha_other_enable'] = array(
    '#type' => 'textfield',
    '#title' => check_plain('Other Forms to enable'),
    '#default_value' => variable_get('mtcaptcha_other_enable', ''),
    '#description' => check_plain('Please give other form ids mtcaptcha should be enabled'),
    '#maxlength' => 400,
  );

  return system_settings_form($form);
}
