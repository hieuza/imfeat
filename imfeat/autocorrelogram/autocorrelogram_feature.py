import Image
import numpy as np
import time

from hadoopy import reporter
try:
    from autocorrelogram.Autocorrelogram import Autocorrelogram
    from autocorrelogram import Autocorrelogram as AC
except ImportError:
    from Autocorrelogram import Autocorrelogram
    import Autocorrelogram as AC

def make_features(image):
    if image.mode != 'RGB':
        reporter.counter('feature_computation', 'NOTRGB')
        return None
    # Use quarter size
    size = image.size[0]*image.size[1]
    new_image = AC.convert_colors_rg64(image.tostring(), size)
    imstr = np.array(new_image, dtype=np.uint8).tostring()
    ac = Autocorrelogram(image.size[1], image.size[0], 64, [1,3,5,7])
    v = np.nan_to_num(np.array(ac.compute(imstr), dtype=np.float32))
    v = v / np.linalg.norm(v)
    return [v.tostring()]
