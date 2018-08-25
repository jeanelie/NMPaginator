Pod::Spec.new do |s|
  s.name         = "NMPaginator"
  s.version      = "2.1.0"
  s.summary      = "NMPaginator is a simple Objective-C class that handles pagination for you."
  s.homepage     = "https://github.com/nmondollot/NMPaginator"

  s.license      = {
    :type => 'Free',
    :text => <<-LICENSE
              Do whatever you want with this piece of code (commercially or free). Attribution would be nice though.
    LICENSE
  }

  s.author                = 'Nicolas Mondollot'
  s.source                = { :git => "https://github.com/jeanelie/NMPaginator.git", :tag => '2.1.0' }
  s.platform              = :ios
  s.ios.deployment_target = '9.0'
  s.frameworks            = 'Foundation', 'UIKit', 'CoreGraphics'
  s.source_files          = 'NMpaginator/NMpaginator.{m,h}'
  s.requires_arc          = true
end
